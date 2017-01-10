#include <iostream>
#include <chrono>

using namespace std::chrono;

#define ARRAY_LENGTH 64*1024*1024

void func1()
{
	int *arr = new int[ARRAY_LENGTH];
	for(int i = 0; i < ARRAY_LENGTH; ++i)
	{
		arr[i] *= 3;
	}
	delete [] arr;
	arr = nullptr;
}

void func2()
{
	int *arr = new int[ARRAY_LENGTH];
	for(int i = 0; i < ARRAY_LENGTH; i += 2)
	{
		arr[i] *= 3;
	}
	delete [] arr;
	arr = nullptr;
}

int main()
{
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	func1();
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(t2 - t1).count();
	std::cout << "func1() run time: " << duration << " μs." << std::endl;

	high_resolution_clock::time_point t3 = high_resolution_clock::now();
	func2();
	high_resolution_clock::time_point t4 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(t4 - t3).count();
	std::cout << "func2() run time: " << duration2 << " μs." << std::endl;

	return 0;
}
