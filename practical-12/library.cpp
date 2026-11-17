// Practical 12 - Mini Project: Library Management System
// Daksh Singh, Roll No 33, AIDS-C
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Item {                    // base class
public:
    int id;
    string title;
    virtual void show() = 0;
    virtual ~Item() {}
};

class Book : public Item {      // inheritance
public:
    bool issued = false;
    Book(int i, string t) { id = i; title = t; }
    void show() {
        cout << id << " - " << title << (issued ? " (Issued)" : " (Available)") << endl;
    }
};

class Library {
    vector<Book> books;         // STL container
public:
    Book& find(int id) {
        for (auto& b : books)
            if (b.id == id) return b;
        throw string("Book not found");
    }
    void add(int id, string t) { books.push_back(Book(id, t)); }
    void list() { for (auto& b : books) b.show(); }
    void issue(int id) {
        Book& b = find(id);
        if (b.issued) throw string("Book already issued");
        b.issued = true;
        cout << "Issued: " << b.title << endl;
    }
    void giveBack(int id) {
        Book& b = find(id);
        b.issued = false;
        cout << "Returned: " << b.title << endl;
    }
    void save() {
        ofstream f("books.txt");
        for (auto& b : books) f << b.id << " " << b.issued << " " << b.title << "\n";
        cout << "Saved to books.txt" << endl;
    }
    void load() {
        ifstream f("books.txt");
        int id; bool is; string t;
        while (f >> id >> is && getline(f >> ws, t)) {
            add(id, t);
            books.back().issued = is;
        }
        cout << "Loaded " << books.size() << " books" << endl;
    }
};

int main() {
    cout << "Name: Daksh Singh | Roll No: 33" << endl;
    cout << "--- Library Management System ---" << endl;

    Library lib;
    lib.load();
    int ch, id;
    string t;

    while (true) {
        cout << "\n1.Add 2.List 3.Issue 4.Return 0.Save & Exit\nChoice: ";
        cin >> ch;
        try {
            if (ch == 1) {
                cout << "Enter id and title: ";
                cin >> id; getline(cin >> ws, t);
                lib.add(id, t);
                cout << "Added: " << t << endl;
            }
            else if (ch == 2) lib.list();
            else if (ch == 3) { cout << "Enter book id: "; cin >> id; lib.issue(id); }
            else if (ch == 4) { cout << "Enter book id: "; cin >> id; lib.giveBack(id); }
            else if (ch == 0) { lib.save(); break; }
            else cout << "Wrong choice" << endl;
        }
        catch (string msg) {
            cout << "Error: " << msg << endl;
        }
    }
    return 0;
}
