//
// @file:           FindOddCntInteger.cpp
// @author:         cuckoo
// @date:           2016/10/14 21:37:51
// @description:    http://blog.jobbole.com/106521/
// @note
//

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <bitset>
using std::bitset;

int main()
{
	vector<int> iv = {1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
	int result = 0;
	for(auto i : iv)
		result ^= i;
	cout << "odd count integer has been found: " << result << endl;

	std::cout << "===============================" << endl;

	vector<int> iv2 = {1, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5, 5};
	int res2 = 0;
	for(auto i : iv2)
		res2 ^= i;

	/* find out the first one(1) bit of res2 represented in binary form
	bitset<32> bitvec(res2);
	// std::cout << bitvec.to_string() << endl;
	std::cout << bitvec << endl;
	int pos = 0;
	for(int i = 0; i != 32; ++i)
	{
		if(bitvec[i] == 1)
		{
			pos = i;
			break;
		}
	}
	//*/
	int pos = 0;
	while(res2)
	{
		if(res2 & 1)
		{
			break;
		}
		else
		{
			res2 >>= 1;
			++pos;
		}
	}

	int val = 1;
	for(int i = 0; i != pos; ++i)
	{
		val *= 2;
	}

	int firstOdd = 0;
	int secondOdd = 0;
	for(auto elem : iv2)
	{
		if(elem & val)		// check if the pos-th binary bit of elem is one(1)
		{
			firstOdd ^= elem;
		}
		else 				// the pos-th binary bit of elem is zero(0)
		{
			secondOdd ^= elem;
		}
	}

	cout << "odd count integer 1 has been found: " << firstOdd << endl;
	cout << "odd count integer 2 has been found: " << secondOdd << endl;

	return 0;
}
