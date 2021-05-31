#include <iostream>
#include <string>
#include "max1.hpp"

int main(){
    /*-----------*/
    int i = 42;
    std::cout << ::max(i,7) << std::endl;
    double f1 = 1.2, f2 = 2.2;
    std::cout << ::max(f1,f2) << std::endl;
    /*-----------*/
    const int c = 42;
    ::max(i,c); //OK: T为int
    ::max(c,c); //ok: t int
    int & ri = i;
    ::max(ri,i); //Ok: T int ,ri中的引用退化
    //::max(4,1.2); // Error: 不知道T该被推断为int还是double
    ::max<double>(4,1.2);
    std::string s;
    //::max("hello",s); //Error: 不知道是const char[6],还是string

    return 0;
}


