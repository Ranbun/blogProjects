#include <iostream>
#include "test.h"
#include "extern_test.h"

using namespace std;

int main()
{
    foo();
    std::cout<<add(10, 30)<<std::endl;
    return 0;
}
