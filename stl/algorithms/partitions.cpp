#include <iostream>
#include <algorithm>
#include <vector>

#define SEPARATOR "**********"
#define SOURCE "https://www.geeksforgeeks.org/stdpartition-in-c-stl/"
#define MESSAGE "C++ has a class in its STL algorithms library which allows us easy partition algorithms using certain inbuilt functions. Partition refers to act of dividing elements of containers depending upon a given condition."
#define OPERATIONS "partition()\nis_partitioned()"
#define OPERATIONS2 "stable_partition()\npartition_point()\npartition_copy()"

bool is_even(int i) { return i%2==0; }

template<typename T>
void showVector(std::vector<T> const& a, int size)
{
std::cout << "Vector\t\t\t\t: ";
for(int i = 0; i < size ; i++){ std::cout << a[i] << " "; }
std::cout << std::endl;
}


int main(){
    // Display user messages
    std::cout << SEPARATOR <<std::endl;
    std::cout << MESSAGE <<std::endl;
    std::cout << "SOURCE:\t\t" << SOURCE << "\n\n";

    // ---------- is_partitioned(beg, end, condition)
    // Check for partition condition is_even()
    std::cout << SEPARATOR <<std::endl;
    std::cout << "OPERATIONS:\n" << OPERATIONS << "\n\n";

    // Setup
    std::cout << SEPARATOR <<std::endl;
    std::vector<int> vect = { 2, 1, 5, 6, 8, 7 };
    showVector(vect, sizeof(vect)/ sizeof(vect[0]));

    // Find if partitions exist in the vector
    bool is_partitioned = std::is_partitioned(vect.begin(), vect.end(), is_even);
    std::cout << "Is the vector partitioned?\t: " <<  is_partitioned << "\n\n";

    // ---------- partition(beg, end, condition)
    // Partition the vector based on is_even()
    std::cout << SEPARATOR <<std::endl;
    std::cout << "Partitioning the vector ..." << std::endl;
    partition(vect.begin(), vect.end(), is_even);

    bool is_partitioned2 = std::is_partitioned(vect.begin(), vect.end(), is_even);
    showVector(vect, sizeof(vect)/ sizeof(vect[0]));
    std::cout << "Is the vector partitioned now?\t: " <<  is_partitioned2 << "\n\n";

    // ---------- Display other operations ...
    std::cout << SEPARATOR <<std::endl;
    std::cout << "Other operations: \n" << OPERATIONS2 << "\n\n";

    // ---------- stable_partition(beg, end, condition)
    // Stable Partition based on is_even()
    std::cout << SEPARATOR <<std::endl;
    std::cout << "Stable Partition of the vector (keeps relative order)..." << std::endl;
    std::vector<int> vect2 = { 2, 1, 5, 6, 8, 7 };
    showVector(vect2, sizeof(vect2)/ sizeof(vect2[0]));

    stable_partition(vect2.begin(), vect2.end(), is_even);
    showVector(vect2, sizeof(vect2)/ sizeof(vect2[0]));
    std::cout << std::endl;

    // ---------- partition_point(beg, end, condition)
    // Iterator pointing to the partition point based on is_even()
    std::cout << SEPARATOR <<std::endl;
    std::cout << "partition_point() creates an interator pointing to the position of the partition point (container must be partitioned) ..." << std::endl;
    showVector(vect2, sizeof(vect2)/ sizeof(vect2[0]));

    // Showing the partition point
    std::vector<int>::iterator it1;
    auto iter = partition_point(vect2.begin(), vect2.end(), is_even);

    std::cout << "typid(iter).name()\t\t: " << typeid(iter).name() << std::endl;
    std::cout << "Partition points\t\t: ";

    // Display the partition points found for is_even()
    for ( it1 = vect2.begin(); it1!=iter; it1++) {
        std::cout << *it1 << " ";
    }
    std::cout << std::endl << std::endl;

    // ---------- partition_copy(beg, end, newBeg1, newBeg2, condition)
    std::cout << SEPARATOR <<std::endl;
    std::cout << "partition_copy() has 5 arguments: start/stop point for source/destination, and condition ..." << std::endl;
    // We will split vect into vect1 and vect2 based on is_even() condition
    std::vector<int> vector1 = { 2, 1, 5, 6, 8, 7 };
    std::vector<int> vector2;
    std::vector<int> vector3;

    // Resizing vector using count_if()
    int hits = count_if (vector1.begin(), vector1.end(), is_even);
    vector2.resize(hits);
    vector3.resize(vector1.size()-hits);

    partition_copy(vector1.begin(), vector1.end(), vector2.begin(), vector3.begin(), is_even);

    // Displaying the results
    showVector(vector1, sizeof(vector1)/ sizeof(vector1[0]));
    showVector(vector2, sizeof(vector2)/ sizeof(vector2[0]));
    showVector(vector3, sizeof(vector3)/ sizeof(vector3[0]));
}