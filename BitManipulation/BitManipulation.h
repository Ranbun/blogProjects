#ifndef BIT_MANIPULATION_H
#define BIT_MANIPULATION_H

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


        static void showBinary(int d)
        {
            using std::cout;
            using std::endl;

            int flag = 1;
            for (int i = 31; i >= 0 ; i--)
            {
                auto da = d & flag;
                if (d & flag)
                {
                    cout << 1;
                }
                else
                {
                    cout << 0;
                }

                flag <<= 1;
            }

            cout << endl;
        }


    };


}

#endif // !BIT_MANIPULATION_H
