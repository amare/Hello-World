//
// @file:           GraphBFS
// @author:         cuckoo
// @date:           2016/10/07 22:52:41
// @description:    Breadth Fisrt Search in a Graph
// @note
//

#include <iostream>
using std::cout;
using std::endl;

#include <queue>
using std::queue;

#include <vector>
using std::vector;

#include <cstring>
using std::memset;

#define NUM_NODE 6
bool visited[NUM_NODE];

vector<int> Graph[NUM_NODE];		// Graph[i] stores all adjacent nodes of node i;

void outputQueue(queue<int> Q)
{
	while(!Q.empty())
	{
		cout << Q.front() << " ";
		Q.pop();
	}
	cout << endl;
}

void BFSTraverse()
{
	memset(visited, 0, sizeof(visited));

	queue<int> Queue;

	for(int i = 0; i < NUM_NODE; ++i)
	{
		if(!visited[i])
		{
			Queue.push(i);
			visited[i] = true;
			cout << "after 1st push: ";
			outputQueue(Queue);
			while(!Queue.empty())
			{
				int u = Queue.front();
				cout << u << endl;
				Queue.pop();
				cout << "after pop: ";
				outputQueue(Queue);
				for(auto iter = Graph[u].cbegin(); iter != Graph[u].cend(); ++iter)
				{
					if(!visited[*iter])
					{
						Queue.push(*iter);
						visited[*iter] = true;
						cout << "after 2nd push: ";
						outputQueue(Queue);
					}
				}
			}
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

	BFSTraverse();

	return 0;
}
