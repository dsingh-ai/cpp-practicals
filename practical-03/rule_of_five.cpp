// Practical 3 - Constructors and Rule of Five
// Daksh Singh, Roll No 33, AIDS-C
#include <iostream>
using namespace std;

class Array {
    int* arr;
    int n;
public:
    Array() { arr = nullptr; n = 0; cout << "Default constructor" << endl; }

    Array(int size) {
        n = size;
        arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = i + 1;
        cout << "Parameterized constructor" << endl;
    }

    // 1. copy constructor (deep copy)
    Array(const Array& o) {
        n = o.n;
        arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = o.arr[i];
        cout << "Copy constructor" << endl;
    }

    // 2. copy assignment
    Array& operator=(const Array& o) {
        if (this != &o) {
            delete[] arr;
            n = o.n;
            arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = o.arr[i];
        }
        cout << "Copy assignment" << endl;
        return *this;
    }

    // 3. move constructor (takes the memory)
    Array(Array&& o) noexcept {
        arr = o.arr; n = o.n;
        o.arr = nullptr; o.n = 0;
        cout << "Move constructor" << endl;
    }

    // 4. move assignment
    Array& operator=(Array&& o) noexcept {
        if (this != &o) {
            delete[] arr;
            arr = o.arr; n = o.n;
            o.arr = nullptr; o.n = 0;
        }
        cout << "Move assignment" << endl;
        return *this;
    }

    // 5. destructor
    ~Array() { delete[] arr; cout << "Destructor" << endl; }

    void show() {
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "(size " << n << ")" << endl;
    }
};

int main() {
    cout << "Name: Daksh Singh | Roll No: 33" << endl;

    Array a;             // default
    Array b(3);          // parameterized
    Array c = b;         // copy constructor
    a = b;               // copy assignment
    Array d = move(c);   // move constructor
    a = move(d);         // move assignment

    a.show();
    c.show();            // c is empty now
    return 0;
}
