#include <iostream>
#include <string>

template<typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}

template<typename Arr, int N>
class Array
{
private:
    Arr m_Array[N];
public:
    int GetSize() const { return N;}
};

int main()
{
    std::cout << "Demonstrating template for a print function\n";
    Print(5);
    Print("Hello");
    Print(5.5f);

    std::cout << "\n\nDemonstrating template for an array class\n";
    Array<std::string, 50> array;
    std::cout << array.GetSize() << std::endl;

    std::cout << "\n\nPress any key to exit: ";
    std::cin.get();
}