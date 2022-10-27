#include "KeyWordsExtern.h"
#include <iostream>

extern int extern_text_var;

void printExternVar()
{
    std::cout << "current: " << extern_text_var << std::endl;
    extern_text_var = 200;

    std::cout << "do update: " <<extern_text_var << std::endl;
}

