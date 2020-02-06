#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    cout << "\n\n*****LOOPS*****\n";
    cout << "There are two kinds of loops: entry-controlled and exit-controlled\n";
    cout << "There are two kinds of loops: entry-controlled and exit-controlled\n";

    cout << "\nCASE1: Entry controlled";
    cout << "\nfor(int i=0; i<255; i++)\n{\n ... \n}\n";

    cout << "\nCASE2: Exit controlled";
    cout << "\nwhile(condition)\n{\n...\n}\n";

    cout << "\nCASE3: Exit controlled";
    cout << "\ndo\n{\n...\n}\nwhile(test_expression)\n";

    cout << "\n\n*****WAYS TO USE LOOPS*****\n";
    cout << "1. Example of range based loops\n";
    vector<int> v = {0, 1, 2, 3, 4, 5};
    for (auto i : v)
        std::cout << i << ' ';

    cout << "\n\n";

    // the initializer may be a braced-init-list
    for (int n : {0, 1, 2, 3, 4, 5})
        std::cout << n << ' ';

    cout << "\n\n";

    cout << "2. Example of for_each loops\n";
    return 0;
}