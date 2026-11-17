// Practical 1 - C++ basics
// Daksh Singh, Roll No 33, AIDS-C
#include <iostream>
using namespace std;

int main() {
    const float PASS = 40;   // constant
    int m1, m2, m3;

    cout << "Name: Daksh Singh | Roll No: 33" << endl;
    cout << "Enter marks of 3 subjects: ";
    cin >> m1 >> m2 >> m3;

    int total = m1 + m2 + m3;
    float avg = total / 3.0;

    cout << "Total = " << total << endl;
    cout << "Average = " << avg << endl;
    cout << "Total % 2 = " << total % 2 << endl;

    if (avg >= PASS && m1 > 0 && m2 > 0 && m3 > 0)
        cout << "Result: Pass" << endl;
    else
        cout << "Result: Fail" << endl;

    if (avg >= 75 || total > 225)
        cout << "Grade: Distinction" << endl;

    return 0;
}
