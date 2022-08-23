#ifndef BIT_MANIPULATION_H
#define BIT_MANIPULATION_H


#include <array>
#include <iostream>

namespace BIT_M
{

    template<typename T>
    class BitManipulate
    {
    public:
        BitManipulate() {}
        ~BitManipulate() {}


        // 某一位设置为 1
        T setBit2One(T d, int bits)
        {
            BitManipulate::showBinary(static_cast<int>(d));
            // | 运算: 只要有一个是1 结果都是1
            d = d | (1 << (bits - 1));
            BitManipulate::showBinary(static_cast<int>(d));
            return d;
        }

        // 某一位设置为 0
        T setBit2Zero(T d, int bits)
        {
            BitManipulate::showBinary(static_cast<int>(d));
            // 取反是一个只和取反位数以及之后所有位数相关的操作
            // 二进制的位数从0开始计算 所以需要 -1 
            // 1 << (bits(3) - 1) = 4 = 0100 
            // ~4 = 1011
            // & 同为 1 则为 1
            d = d & (~(1 << (bits - 1)));

            BitManipulate::showBinary(static_cast<int>(d));
            return d;

        }

        // 某一位取反
        T setBit2Negate(T d, int bits)
        {
            BitManipulate::showBinary(static_cast<int>(d));
            
            // 转换过程
            // ^ 异或运算 1 ^ 0 == 1 / 0 ^ 1 == 1  其余的情况都是 0 
            // d(15) == 1111 bits = 3
            // 1 << bits - 1 == 0100
            // 1111
            // 0100 ^
            // 1011 

            d = d ^ (1 << (bits - 1));

            BitManipulate::showBinary(static_cast<int>(d));
            return d;
        }


        static void show(int d)
        {
            using std::cout;
            using std::endl;


            cout << d << endl;

        }


        // 效率较低 - 可以优化 
        static void showBinary(int d)
        {
            using std::cout;
            using std::endl;
            using std::array;

            array<int, 32> num;

            num.fill(0);
            int flag = 1;
            for (int i = 31; i >= 0; i--)
            {
                auto da = d & flag;
                if (d & flag)
                {
                    num[i] = 1;
                }
                else
                {
                    num[i] = 0;
                }

                flag = flag << 1;
            }


            // 查找第一个不是零的数 
            int index = 0;
            for (auto i = 0; i < num.size(); i++)
            {
                if (num[i] != 0)
                {

                    i == 0 ? index = i : index = i - 1;
                    break;
                }
            }

            // 输出转换结果
            for (auto i = index; i < num.size(); i++)
            {
                cout << num[i];

            }
            cout << endl;
        }


    };


}

#endif // !BIT_MANIPULATION_H
