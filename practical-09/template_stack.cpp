// Practical 9 - Generic stack using template
// Daksh Singh, Roll No 33, AIDS-C
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Stack {
    vector<T> v;
public:
    void push(T x) { v.push_back(x); }
    void pop() {
        if (v.empty()) { cout << "Stack is empty!" << endl; return; }
        cout << "Popped: " << v.back() << endl;
        v.pop_back();
    }
    bool isEmpty() { return v.empty(); }
    T top() { return v.back(); }
};

int main() {
    cout << "Name: Daksh Singh | Roll No: 33" << endl;

    Stack<int> a;
    a.push(10); a.push(20);
    cout << "Top = " << a.top() << endl;
    a.pop(); a.pop(); a.pop();   // third pop is on empty stack

    Stack<float> b;
    b.push(1.5); b.push(2.5);
    b.pop();

    Stack<string> c;
    c.push("Daksh"); c.push("Singh");
    c.pop();
    return 0;
}
