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


        // ĳһλ����Ϊ 1
        T setBit2One(T, int bits)
        {

        }

        // ĳһλ����Ϊ 0
        T setBit2Zero(T, int bits)
        {

        }

        // ĳһλȡ��
        T setBit2Negate(T, int bits)
        {

        }


        static void show(int d)
        {
            using std::cout;
            using std::endl;


            cout << d << endl;

        }


        // Ч�ʽϵ� - �����Ż� 
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


            // ���ҵ�һ����������� 
            int index = 0;
            for (auto i = 0; i < num.size(); i++)
            {
                if (num[i] != 0)
                {

                    i == 0 ? index = i : index = i - 1;
                    break;
                }
            }


            // ���ת�����
            for (auto i = index; i < num.size(); i++)
            {
                cout << num[i];

            }
            cout << endl;
        }


    };


}

#endif // !BIT_MANIPULATION_H
