//
// @file:           count_number_of_one.cc
// @author:         cuckoo
// @date:           2016/12/09 10:17:26
// @description:    https://www.zhihu.com/question/52726115 @Comzyh
// @note
//

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <bitset>
using std::bitset;

int bits(unsigned long x)
{
    int count = 0;
    while(x)
    {
        count += x & 1;
        x >>= 1;
    }

    return count;
}

// ======================================================================================
//
/*  x    00100100
 *  -x   11011100
 *  x&-x 00000100
 */
// ======================================================================================

int bits2(unsigned long x)
{
    int count = 0;
    while(x)
    {
        ++count;
        x -= x & -x;
    }

    return count;
}

int bits3(unsigned long x)
{
    x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);
    x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
    x = (x & 0x0000ffff) + ((x >> 16) & 0x0000ffff);

    return x;
}

int main()
{
    cout << "Input a number which is not longer than 32-bit:" << endl;
    unsigned long number;
    while(cin >> number)
    {
        cout << bits(number) << " " << bits2(number) << " " << bits3(number) << endl;
    }

    return 0;
}
