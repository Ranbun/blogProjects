#include <iostream>
#include "Person.h"

int main()
{

    auto test = new Author;
    delete test;
    test = nullptr;
    return 0;

}
