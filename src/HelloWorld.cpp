#include <iostream>
#include "testheader.h"

int main()
{

    std::cout << "Hello World" << std::endl;
    Num num = Num(5);
    std::cout << "Num "<<num.getNum()<<std::endl;
    
    
    std::cout << "Hello World" << std::endl;
    std::cout << "Num "<<num.getNum()<<std::endl;
}

