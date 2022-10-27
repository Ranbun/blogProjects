#include <iostream>
#include "BitManipulation.h" 

using namespace std;

int main()
{
    using BIT_M::BitManipulate;

    BitManipulate<int> tool;
    tool.setBit2Zero(15,3);
    tool.setBit2One(16, 1);
    tool.setBit2Negate(15, 3);

    return 0;
}
