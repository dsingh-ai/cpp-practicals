// Practical 8 - Singleton design pattern
// Daksh Singh, Roll No 33, AIDS-C
#include <iostream>
using namespace std;

class Settings {
    static Settings* obj;
    string theme;
    Settings() { theme = "Light"; cout << "Settings object created" << endl; }
public:
    static Settings* getInstance() {
        if (obj == nullptr) obj = new Settings();
        return obj;
    }
    void setTheme(string t) { theme = t; }
    string getTheme() { return theme; }
};

Settings* Settings::obj = nullptr;

int main() {
    cout << "Name: Daksh Singh | Roll No: 33" << endl;

    Settings* s1 = Settings::getInstance();
    Settings* s2 = Settings::getInstance();   // same object again

    s1->setTheme("Dark");
    cout << "Theme from s2 = " << s2->getTheme() << endl;

    if (s1 == s2) cout << "Both point to the same object" << endl;
    return 0;
}
