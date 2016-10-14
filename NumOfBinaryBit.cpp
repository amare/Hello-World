//
// @file:           NumOfBinaryBit.cpp
// @author:         cuckoo
// @date:           2016/10/14 23:22:31
// @description:    how many binary bits in a 32bit integer?
// @note			see http://blog.csdn.net/lqk1985/article/details/2469593
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int NumOfBinaryBit1(unsigned n)
{
	int count = 0;		//@gps: initialization...
	while(n)
	{
		count += n & 1;
		n >>= 1;
	}

	return count;
}

int NumOfBinaryBit2(unsigned n)
{
	int count = 0;
	while(n)
	{
		n &= n - 1;
		++count;
	}

	return count;
}

int NumOfBinaryBit3(unsigned n)
{
	short CntArr[255];
	for(int i = 0; i != 256; ++i)
	{
		CntArr[i] = NumOfBinaryBit2(i);
	}

	short count = 0;
	while(n)
	{
		count += CntArr[n & 255];
		n >>= 8;
	}

	return count;
}

int main()
{
	unsigned n;
	cout << "Input a 32bit integer: ";
	while(cin >> n)
	{
		cout << NumOfBinaryBit1(n) << endl;
		cout << NumOfBinaryBit2(n) << endl;
		cout << NumOfBinaryBit3(n) << endl;
		cout << "Input a 32bit integer: ";
	}

	return 0;
}
