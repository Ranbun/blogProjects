#include <iostream>
#include "BitManipulation.h" 



using namespace std;

int main()
{
    using BIT_M::BitManipulate;


    BitManipulate<int> tool;
    tool.show(8);
    tool.showBinary(8);


    // cout << "Hello World!" << endl;

    return 0;
}
