// Practical 11 - CSV file with student records
// Daksh Singh, Roll No 33, AIDS-C
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    cout << "Name: Daksh Singh | Roll No: 33" << endl;

    // write records
    ofstream out("students.csv");
    if (!out) { cout << "File not opened" << endl; return 1; }
    out << "33,Daksh,85\n";
    out << "12,Riya,90\n";
    out << "27,Aman,78\n";
    cout << "tellp() after writing = " << out.tellp() << endl;
    out.seekp(0);                       // go back to start
    cout << "tellp() after seekp(0) = " << out.tellp() << endl;
    out.close();

    // read records
    ifstream in("students.csv");
    string line;
    cout << "\nRecords (id,name,marks):" << endl;
    while (getline(in, line))
        cout << line << endl;

    in.clear();
    in.seekg(3);                        // skip "33,"
    cout << "\ntellg() after seekg(3) = " << in.tellg() << endl;
    getline(in, line);
    cout << "Read from there: " << line << endl;
    in.close();
    return 0;
}
