// Practical 7 - Function and operator overloading
// Daksh Singh, Roll No 33, AIDS-C
#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }
float add(float a, float b) { return a + b; }

class Complex {
    int real, img;
public:
    Complex(int r = 0, int i = 0) { real = r; img = i; }

    Complex operator+(Complex c) {
        return Complex(real + c.real, img + c.img);
    }

    void show() { cout << real << " + " << img << "i" << endl; }
};

int main() {
    cout << "Name: Daksh Singh | Roll No: 33" << endl;

    cout << "add(5, 7) = " << add(5, 7) << endl;
    cout << "add(2.5, 1.5) = " << add(2.5f, 1.5f) << endl;

    Complex c1(3, 4), c2(2, 5);
    Complex c3 = c1 + c2;
    cout << "c1 = "; c1.show();
    cout << "c2 = "; c2.show();
    cout << "c1 + c2 = "; c3.show();
    return 0;
}
