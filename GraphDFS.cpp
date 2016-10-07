//
// @file:           GraphDFS.cpp
// @author:         cuckoo
// @date:           2016/10/08 00:17:33
// @description:    Depth First Search in a Graph
// @note
//

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <cstring>
using std::memset;

#define NUM_NODE 6
bool visited[NUM_NODE];

vector<int> Graph[NUM_NODE];		// Graph[i] stores all adjacent nodes of node i;

void DFSTraverse(int i)
{
	visited[i] = true;
	cout << i << endl;

	for(auto iter = Graph[i].cbegin(); iter != Graph[i].cend(); ++iter)
	{
		if(!visited[*iter])
		{
			DFSTraverse(*iter);
		}
	}
}

int main()
{
	Graph[0] = {1, 2, 3};
	Graph[1] = {0, 2, 4};
	Graph[2] = {0, 1, 5};
	Graph[3] = {0};
	Graph[4] = {1, 6};
	Graph[5] = {2};
	Graph[6] = {4};

	memset(visited, 0, sizeof(visited));

	for(int i = 0; i < NUM_NODE; ++i)
	{
		if(!visited[i])
		{
			DFSTraverse(i);
		}
	}

	return 0;
}
