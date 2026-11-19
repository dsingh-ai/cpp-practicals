// Practical 6 - Abstract class and runtime polymorphism
// Daksh Singh, Roll No 33, AIDS-C
#include <iostream>
using namespace std;

class Shape {
public:
    virtual float area() = 0;     // pure virtual
    virtual ~Shape() {}
};

class Circle : public Shape {
    float r;
public:
    Circle(float x) { r = x; }
    float area() { return 3.14 * r * r; }
};

class Rectangle : public Shape {
    float l, b;
public:
    Rectangle(float x, float y) { l = x; b = y; }
    float area() { return l * b; }
};

class Triangle : public Shape {
    float b, h;
public:
    Triangle(float x, float y) { b = x; h = y; }
    float area() { return 0.5 * b * h; }
};

int main() {
    cout << "Name: Daksh Singh | Roll No: 33" << endl;

    Shape* s[3];
    s[0] = new Circle(5);
    s[1] = new Rectangle(4, 6);
    s[2] = new Triangle(3, 8);

    string names[3] = {"Circle", "Rectangle", "Triangle"};
    for (int i = 0; i < 3; i++) {
        cout << names[i] << " area = " << s[i]->area() << endl;
        delete s[i];
    }
    return 0;
}
