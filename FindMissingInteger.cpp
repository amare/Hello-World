//
// @file:           FindMissingInteger.cpp
// @author:         cuckoo
// @date:           2016/10/14 16:22:22
// @description:    http://blog.jobbole.com/106521/
// @note
//

#include <iostream>
using std::cout;
using std::endl;

#include <unordered_map>
using std::unordered_map;

#include <random>
using std::uniform_int_distribution;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;
using std::unique;

vector<int> iv;
// generate a array which lacks of certain integer
void InitArr()
{
	// produces a random integer value
	// see http://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    auto missValue = dis(gen);
    cout << "miss integer has been created: " << missValue << endl;

	for(int i = 1; i != 101; ++i)
	{
		if(i == missValue)
			continue;
		iv.push_back(i);
	}
}

void algorithm1()
{
	unordered_map<int, bool> UnorderdeArr;
	for(int i = 1; i != 101; ++i)
	{
		UnorderdeArr[i] = false;
	}

	// change default value to true if the corresponding key exists in array
	for(auto iter = iv.cbegin(); iter != iv.cend(); ++iter)
	{
		UnorderdeArr[*iter] = true;
	}

	// traverse modified unordered_map, and find the missing integer
	for(const auto &elem : UnorderdeArr)
	{
		if(elem.second == false)
		{
			cout << "missing integer has been found: " << elem.first << endl;
		}
	}
}

void algorithm2()
{
	sort(iv.begin(), iv.end());
	auto end_unique = unique(iv.begin(), iv.end());
	iv.erase(end_unique, iv.end());

	if(iv.at(0) != 1)
		cout << "missing integer has been found: " << '1' << endl;
	if(iv.at(iv.size()-1) != 100)
		cout << "missing integer has beens found: " << "100" << endl;
	for(int i = 0; i != iv.size() - 1; ++i)
	{
		if(iv.at(i) + 1 != iv.at(i+1))
		{
			cout << "missing integer has been found: " << iv.at(i) + 1 << endl;
		}
	}
}

void algorithm3()
{
	int sum = 0;
	for(int i = 1; i != 101; ++i) { sum += i;}
	for(auto i : iv)
		sum -= i;
	cout << "missing integer has been found: " << sum << endl;
}

int main()
{
	InitArr();

	algorithm1();

	algorithm2();

	algorithm3();

	return 0;
}
