#include <iostream>
#include "TestExtern.h"
#include "KeyWordsExtern.h"

using namespace std;

int main()
{
    printExternVar();
    std::cout<<"add result: "<<add(10, 30)<<std::endl;
    return 0;
}
