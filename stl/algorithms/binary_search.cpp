#include <iostream>
#include <algorithm>
#include <vector>

// http://www.cplusplus.com/reference/algorithm/binary_search/
void showList(int a[], int size)
{
    for(int i = 0; i < size ; i++){ std::cout << a[i] << " "; }
}

bool myFunction (int i, int j) { return (i<j);}

int main () {
    int aList[] = {1,2,3,4,5,4,3,2,1};
    int aSize = sizeof(aList) / sizeof(aList[0]);
    std::vector<int> v(aList, aList+aSize);

    std::cout << "Original List : ";
    showList(aList, aSize);
    std::cout << std::endl;

    std::sort(v.begin(), v.end());

    std::cout << "\tsearching for a 3 ... \t\t";
    if(std::binary_search(v.begin(), v.end(), 3))
        std::cout << "Found one!\n"; else std::cout << "Not found.\n";

    std::sort(v.begin(), v.end(), myFunction);

    std::cout << "\tsearching for a 6 ... \t\t";
    if(std::binary_search(v.begin(), v.end(), 6, myFunction))
    std::cout << "Found one!\n"; else std::cout << "Not found.\n";

    return 0;
}