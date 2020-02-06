#include <iostream>

using namespace std;

int main()
{
    // Input
    cout << "\nStandard Input Stream (cin)\n";
    int age;

    cout << "Enter your age:";
    cin >> age;
    cout << "Your age is: " << age;

    // Output
    cout << "\nStandard Output Stream (cout)\n";
    char sample[] = "\n\nGeeksforGeeks\n";

    cout << sample << " - A computer science portal for geeks\n\n";

    // Un-buffered standard error stream (cerr)
    cout << "\nUnbuffered standard error stream (cerr)\n";
    cerr << "An error occured (just joking)\n";

    // buffered standard error stream (clog)
    cout << "\nBuffered standard error stream (clog)\n";
    clog << "An error occured\n";

    return 0;
}