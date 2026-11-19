// Practical 4 - Smart pointers (RAII)
// Daksh Singh, Roll No 33, AIDS-C
#include <iostream>
#include <memory>
using namespace std;

class Book {
public:
    string name;
    Book(string n) { name = n; cout << name << " created" << endl; }
    ~Book() { cout << name << " deleted" << endl; }
};

int main() {
    cout << "Name: Daksh Singh | Roll No: 33" << endl;

    // unique_ptr - only one owner
    {
        unique_ptr<Book> p1 = make_unique<Book>("C++ Book");
        unique_ptr<Book> p2 = move(p1);   // owner changed
        if (!p1) cout << "p1 is empty now" << endl;
        cout << "p2 has " << p2->name << endl;
    }   // deleted here automatically

    // shared_ptr - many owners
    {
        shared_ptr<Book> s1 = make_shared<Book>("Java Book");
        shared_ptr<Book> s2 = s1;
        cout << "Owners = " << s1.use_count() << endl;
        s1.reset();
        cout << "Owners after reset = " << s2.use_count() << endl;
    }   // deleted when last owner goes

    return 0;
}
