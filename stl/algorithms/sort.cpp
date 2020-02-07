#include <iostream>
#include <algorithm>
#include <vector>

template<typename A>
void showArray(A a[], int size) {
    std::cout << "Array\t\t\t\t: ";
    for(int i = 0; i < size; i++){ std::cout << a[i] << " "; }
}

template<typename T>
void showVector(std::vector<T> const& a, int size) {
    std::cout << "Vector\t\t\t\t: ";
    for(int i = 0; i < size ; i++){ std::cout << a[i] << " "; }
    std::cout << std::endl;
}

int main() {

    std::cout << "*****Sorting an integer array*****\n";
    std::cout << std::endl << "Before sort()\n:";
    int a[10] = {1,5,8,9,6,7,3,4,2,0};
    int asize = sizeof(a) / sizeof(a[0]);
    showArray(a, asize);

    std::sort(a, a+asize);

    std::cout << std::endl << "After sort()\n:";
    showArray(a, asize);
    std::cout << "\n\n";

    std::cout << "*****Sorting a Vector*****\n";
    int arr[] = {10,20,5,23,42,15};
    int sizeArr = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> vect(arr, arr+sizeArr);
    showVector(vect, sizeArr);
    sort(vect.begin(), vect.end());
    showVector(vect, sizeArr);
    std::cout << "\n\n";
}
