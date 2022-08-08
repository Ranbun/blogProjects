#include "extern_test.h"
#include <iostream>

extern int test_;

void foo()
{
    test_ = 200;
    std::cout << test_ << std::endl;
}

