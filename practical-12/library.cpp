// Practical 12 - Mini Project: Library Management System
// Daksh Singh, Roll No 33, AIDS-C
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Item {                    // base class
protected:
    int id;
    string title;
public:
    Item(int i, string t) { id = i; title = t; }
    int getId() { return id; }
    string getTitle() { return title; }
    virtual void show() = 0;    // every item shows itself differently
    virtual ~Item() {}
};

class Book : public Item {      // Book is an Item
    string author;
    bool issued;
public:
    Book(int i, string t, string a, bool is = false) : Item(i, t) {
        author = a;
        issued = is;
    }
    string getAuthor() { return author; }
    bool isIssued() { return issued; }
    void setIssued(bool x) { issued = x; }
    void show() {
        cout << id << " | " << title << " | " << author
             << " | " << (issued ? "Issued" : "Available") << endl;
    }
};

class Library {
    vector<Book> books;         // all books are kept here
    string file = "books.csv";
public:
    Book& find(int id) {
        for (auto& b : books)
            if (b.getId() == id) return b;
        throw string("No book with id " + to_string(id));
    }

    void add(int id, string t, string a) {
        for (auto& b : books)
            if (b.getId() == id) throw string("Id already used");
        books.push_back(Book(id, t, a));
        cout << "Added: " << t << endl;
    }

    void list() {
        if (books.empty()) { cout << "No books yet" << endl; return; }
        for (auto& b : books) b.show();
    }

    void search(string word) {
        bool found = false;
        for (auto& b : books) {
            if (b.getTitle().find(word) != string::npos ||
                b.getAuthor().find(word) != string::npos) {
                b.show();
                found = true;
            }
        }
        if (!found) cout << "Nothing found for \"" << word << "\"" << endl;
    }

    void issue(int id) {
        Book& b = find(id);
        if (b.isIssued()) throw string("Book is already issued");
        b.setIssued(true);
        cout << "Issued: " << b.getTitle() << endl;
    }

    void giveBack(int id) {
        Book& b = find(id);
        if (!b.isIssued()) throw string("This book was not issued");
        b.setIssued(false);
        cout << "Returned: " << b.getTitle() << endl;
    }

    void save() {
        ofstream f(file);
        if (!f) throw string("Could not open " + file);
        for (auto& b : books)
            f << b.getId() << "," << b.getTitle() << "," << b.getAuthor()
              << "," << b.isIssued() << "\n";
        cout << "Saved " << books.size() << " books to " << file << endl;
    }

    void load() {
        ifstream f(file);
        if (!f) { cout << "No saved file, starting fresh" << endl; return; }
        string line, id, t, a, is;
        while (getline(f, line)) {
            stringstream ss(line);
            getline(ss, id, ',');
            getline(ss, t, ',');
            getline(ss, a, ',');
            getline(ss, is);
            books.push_back(Book(stoi(id), t, a, is == "1"));
        }
        cout << "Loaded " << books.size() << " books from " << file << endl;
    }
};

int main() {
    cout << "Name: Daksh Singh | Roll No: 33" << endl;
    cout << "--- Library Management System ---" << endl;

    Library lib;
    lib.load();
    int ch, id;
    string t, a;

    while (true) {
        cout << "\n1.Add 2.List 3.Search 4.Issue 5.Return 0.Save & Exit\nChoice: ";
        if (!(cin >> ch)) break;
        try {
            if (ch == 1) {
                cout << "Book id: ";  cin >> id;
                cout << "Title: ";    getline(cin >> ws, t);
                cout << "Author: ";   getline(cin >> ws, a);
                lib.add(id, t, a);
            }
            else if (ch == 2) lib.list();
            else if (ch == 3) {
                cout << "Enter title or author: ";
                getline(cin >> ws, t);
                lib.search(t);
            }
            else if (ch == 4) { cout << "Book id: "; cin >> id; lib.issue(id); }
            else if (ch == 5) { cout << "Book id: "; cin >> id; lib.giveBack(id); }
            else if (ch == 0) { lib.save(); break; }
            else cout << "Wrong choice" << endl;
        }
        catch (string msg) {
            cout << "Error: " << msg << endl;
        }
    }
    return 0;
}
