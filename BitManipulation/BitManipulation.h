#ifndef BIT_MANIPULATION_H
#define BIT_MANIPULATION_H


#include <array>

namespace BIT_M
{

    template<typename T>
    class BitManipulate
    {
    public:
        BitManipulate() {}
        ~BitManipulate() {}


        // 某一位设置为 1
        T setBit2One(T, int bits)
        {

        }

        // 某一位设置为 0
        T setBit2Zero(T, int bits)
        {

        }

        // 某一位取反
        T setBit2Negate(T, int bits)
        {

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
