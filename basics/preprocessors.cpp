#include <iostream>
#include <string>

// macro definition
#define LIMIT 5
// macro with parameter
#define AREA(l, b) (l * b)

using namespace std;

int main() {
    char types[4][30] = {"Macros", "File Inclusion", "Conditional Compilation", "Other directives"};

    cout << "\n\nThese are the different types of proprocessors for C++: \n";
    for (int i = 0; i < 4; i++)
        cout << types[i] << "\n";

    cout << "\n\n*****MACROS*****\n";
    cout << "This is a MACRO example using #define LIMIT 5: \n";
    for (int i = 0; i < LIMIT; i++) {
        cout << i << "\n";
    }

    cout << "\n\nThis is a MACRO example using parameters: \n";
    int l1 = 10, l2 = 5, area;
    area = AREA(l1, l2);
    cout << "Area of rectangle is: " << area << "\n";

    cout << "\n\n*****File Inclusions*****\n";
    cout << "There are two types: header (standard) and user defined files\n";
    cout << "HEADER      : #include<file_name>   >>>> this looks in the standard directory for \"file_name\"\n";
    cout << "USER DEFINED: #include \"filename\"   >>>> this looks in your folder structure for \"filename\"\n";

    cout << "\n\n*****Conditional Compilation*****\n";
    cout << "#ifdef and #endif let you conditionally compile parts of a program";

    cout << "\n\n*****Other directives*****\n";
    cout << "#undef:    undefines existing macros.\n";
    cout << "#pragma:   gives order of operation for compiling."
            "\n           @See _ _attribute_ _ ((constructor)) "
            "\n           @See _ _attribute_ _((destructor))\n";
    return 0;
}