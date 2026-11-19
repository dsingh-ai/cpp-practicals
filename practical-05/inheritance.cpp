// Practical 5 - Single and multilevel inheritance
// Daksh Singh, Roll No 33, AIDS-C
#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) { name = n; age = a; }
    void showPerson() { cout << "Name: " << name << ", Age: " << age << endl; }
};

class Student : public Person {          // single
protected:
    int rollNo;
public:
    Student(string n, int a, int r) : Person(n, a) { rollNo = r; }
    void showStudent() { showPerson(); cout << "Roll No: " << rollNo << endl; }
};

class GraduateStudent : public Student { // multilevel
    string topic;
public:
    GraduateStudent(string n, int a, int r, string t) : Student(n, a, r) { topic = t; }
    void showGrad() { showStudent(); cout << "Research: " << topic << endl; }
};

int main() {
    cout << "Name: Daksh Singh | Roll No: 33" << endl;

    cout << "\nStudent:" << endl;
    Student s("Daksh Singh", 19, 33);
    s.showStudent();

    cout << "\nGraduate Student:" << endl;
    GraduateStudent g("Riya Patil", 23, 7, "Machine Learning");
    g.showGrad();
    return 0;
}
