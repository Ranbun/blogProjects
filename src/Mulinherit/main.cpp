#include <iostream>
#include "Person.cpp"

void main()
{
    auto test = new Author("test");
    delete test;
    test = nullptr;
}