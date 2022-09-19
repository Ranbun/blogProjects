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


        // ĳһλ����Ϊ 1
        T setBit2One(T d, int bits)
        {
            BitManipulate::showBinary(static_cast<int>(d));
            // | ����: ֻҪ��һ����1 �������1
            d = d | (1 << (bits - 1));
            BitManipulate::showBinary(static_cast<int>(d));
            return d;
        }

        // ĳһλ����Ϊ 0
        T setBit2Zero(T d, int bits)
        {
            BitManipulate::showBinary(static_cast<int>(d));
            // ȡ����һ��ֻ��ȡ��λ���Լ�֮������λ����صĲ���
            // �����Ƶ�λ����0��ʼ���� ������Ҫ -1 
            // 1 << (bits(3) - 1) = 4 = 0100 
            // ~4 = 1011
            // & ͬΪ 1 ��Ϊ 1
            d = d & (~(1 << (bits - 1)));

            BitManipulate::showBinary(static_cast<int>(d));
            return d;

        }

        // ĳһλȡ��
        T setBit2Negate(T d, int bits)
        {
            BitManipulate::showBinary(static_cast<int>(d));
            
            // ת������
            // ^ ������� 1 ^ 0 == 1 / 0 ^ 1 == 1  ������������ 0 
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


        // Ч�ʽϵ� - �����Ż� 
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
