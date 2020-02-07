#include <iostream>
#include <algorithm>
#include <array>
#include <numeric>

int modulo2(int i){
    return i%2;
}

int negative(int i){
    return i<0;
}

template<typename T>
void showArray(T a, int size)
{
for(int i = 0; i < size ; i++){ std::cout << a[i] << " "; }
}

int main() {
    std::cout << "******************************\nArray algorithms\n\n";
    std::cout << "all_of(), any_of(), and none_of()\t returns true if all/any/none of the elements match a condition, else false\n";
    std::cout << "copy_n()\t\t\t\t copies elements of one array to another.  This provides a deep copy.\n";
    std::cout << "iota()\t\t\t\t\t used to assign continuously incremented value to an array\n\n";

    // all_of() example
    std::array<int,8> foo = {3,5,7,11,13,17,19,23};
    std::cout << "Checking that ALL are odd numbers \t\t\t:";
    std::cout << std::all_of(foo.begin(), foo.end(), modulo2) << std::endl;
    // alternatively without declaring the unary predicate function...
//    std::cout << std::all_of(foo.begin(), foo.end(), [](int i) {return i%2;});

    std::cout << "Checking for ANY numbers less than zero \t\t:";
    std::cout << std::any_of(foo.begin(), foo.end(), negative) << std::endl;

    std::cout << "Checking that NONE of the numbers are greater than 20 \t:";
    std::cout << std::none_of(foo.begin(), foo.end(), negative) << std::endl;

    std::cout << "copy_n(source, sizeArr=4, destination)\t\t\t:";
    int arr[6] = {1,2,3,4,5,6};
    int arr_copy[4];
    std::copy_n(arr, 4, arr_copy);

    showArray(arr, sizeof(arr)/ sizeof(arr[0]));
    std::cout << "\t ---> \t";
    showArray(arr_copy, sizeof(arr_copy)/ sizeof(arr_copy[0]));

    std::cout << std::endl;
    std::cout << "iota(array, size=5, startingNumber=5)\t\t\t:";

    // initializing an array of zeros with length 5
    int incrementedArray[5] = {0};

    showArray(incrementedArray, sizeof(incrementedArray) / sizeof(incrementedArray[0]));
    std::iota(incrementedArray, incrementedArray+5, 19);
    std::cout << "\t ---> \t";
    showArray(incrementedArray, sizeof(incrementedArray) / sizeof(incrementedArray[0]));
    std::cout << std::endl;

    return 0;
}