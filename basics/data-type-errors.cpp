// C++ program to demonstrate looping errors for data-types
// This program should throw errors when compiling!
#include <iostream>

using namespace std;

int main() {

    cout << "Select one of the following... THIS WILL TRIGGER AN INFINITE LOOP!\n";
    cout <<  "1: char\n";
    cout <<  "2: bool\n";
    cout <<  "3: short\n";
    cout <<  "4: unsigned short\n";
    cout << "Your selection: ";
    char selection;
    cin >> selection;
    cout << "\n\n";

    if (selection == '1') {
        for (char a = 0; a <= 225; a++)
            cout << a;
        return 0;
    }
    else if (selection == '2') {
        bool a = true;
        for (a = 1; a <= 5; a++)
            cout << a;
        return 0;
    } else if (selection == '3') {
        short a;
        for (a = 32767; a < 32770; a++)
            cout << a << "\n";
        return 0;
    } else if(selection == '4'){
        unsigned short a;
        for (a = 65532; a < 65536; a++)
            cout << a << "\n";
        return 0;
    }
    else {
        cout << "Nothing was selected ... good-bye\n";
        return 0;
    }
}