#include <iostream>
#include<valarray>

#define MESSAGE1 "C++98 introduced a special container called valarray to hold and provide mathematical operations on arrays efficiently.\n"
#define MESSAGE2 "It supports element-wise mathematical operations and various forms of generalized subscript operators, slicing and indirect access.\n"
#define MESSAGE3 "As compare to vectors, valarrays are efficient in certain mathematical operations than vectors also.\n"
#define PUBLIC_MEMBER_FUNCTIONS "Public member functions in valarray class :\napply \nsum \nmin \nmax \nshift \ncshift \nswap "
#define SEPARATOR "**********"

int main(){
    std::cout << MESSAGE1 << MESSAGE2 << MESSAGE3 "\n\n" << PUBLIC_MEMBER_FUNCTIONS << "\n\n";

    // ---------- APPLY and SHIFT and CSHIFT
    // Initializing and show valarray
    std::cout << SEPARATOR << "\n" <<"FUNCTION: apply (increment of 5)\n";
    std::valarray<int> varr = { 10, 2, 20, 1, 30 };
    std::cout << "Valarray\t: ";
    for (int &x: varr) std::cout << x << " ";
    std::cout << "\n";

    // Using apply() to increment all elements by 5
    std::valarray<int> varr1;
    varr1 = varr.apply([](int x){return x=x+5;});
    std::cout << "apply(x+=5)\t: ";
    for (int &x: varr1) std::cout << x << " ";
    std::cout << "\n";

    // shift(2)
    std::valarray<int> var_shift;
    var_shift = varr.shift(2);
    std::cout << "shift(2)\t: ";
    for ( int&x : var_shift) std::cout << x << " ";
    std::cout << std::endl;

    //cshift(-3)
    std::valarray<int> c_shift;
    c_shift = varr.cshift(-3);
    std::cout << "cshift(-3)\t: ";
    for ( int&x : c_shift) std::cout << x << " ";
    std::cout << std::endl;

    //swap()

    std::cout << "varr.swap(c_shift)\t: ";
    std::cout << "\tvarr\t";
    for ( int&x : varr) std::cout << x << " ";

    std::cout << "\tc_shift\t";
    for ( int&x : c_shift) std::cout << x << " ";

    varr.swap(c_shift);
    std::cout << "\tvarr(new)   ";
    for ( int&x : varr) std::cout << x << " ";
    std::cout << std::endl;

    // ---------- MIX and MAX and SUM
    std::cout << SEPARATOR << "\n" <<"FUNCTION: \tmin\t\tmax\t\tsum\n";
    std::cout << "old\t\t";
    std::cout << varr.max() << "\t\t" << varr.min() << "\t\t" << varr.sum() << std::endl;
    std::cout << "new\t\t";
    std::cout << varr1.max() << "\t\t" << varr1.min() << "\t\t" << varr1.sum() << std::endl;

    return 0;
}