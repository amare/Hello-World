//
// @file:           BipartiteGraphMaxMatch.cpp
// @author:         cuckoo
// @date:           2016/10/07 10:34:00
// @description:    resolve maximum matching problem using Hungarian Algorithm
// @note			see detail(http://blog.jobbole.com/106084)
//

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <cstring>
using std::memset;

#include <queue>
using std::queue;

struct Edge
{
	int from;
	int to;
	int weight;

	Edge(int _from, int _to, int _weight) : from(_from), to(_to), weight(_weight){}
};
vector<Edge> edges;		// all of the edges

const int MaxNode = 12; 		// number of nodes of graph
const int num_left = MaxNode / 2;
vector<int> G[MaxNode + 1];		// G[i] stores edges which starts from i node

int matching[MaxNode + 1];		// matching[i] stores i's matching point
int check[MaxNode + 1];			// check[i] shows if i is in Alternating Path


queue<int> Q;
int prev[MaxNode+1];
int Hungarian()
{
	int ans = 0;
	memset(matching, -1, sizeof(matching));
	memset(check, -1, sizeof(check));
	cout << "====== Matching Chain ======" << endl;
	for(int i = 1; i <= num_left; ++i)
	{
		if(matching[i] == -1)
		{
			while(!Q.empty()) Q.pop();
			Q.push(i);
			prev[i] = -1;
			bool flag = false;		// agumenting path don't exsits.

			while(!Q.empty() && !flag)
			{
				int u = Q.front();
				Q.pop();
				for(auto iter = G[u].cbegin(); iter != G[u].cend() && !flag; ++iter)
				{
					int v = edges.at(*iter).to;
					if(check[v] != i)
					{
						check[v] = i;		// node is in alternating path
						Q.push(matching[v]);
						if(matching[v] > 0)	// not match
						{
							prev[matching[v]] = u;
						}
						else
						{
							flag = true;
							int _u = u;
							int _v = v;
							while(_u != -1)
							{
								cout << _v << " -> " << _u << " -> ";
								int temp = matching[_u];
								matching[_u] = _v;
								matching[_v] = _u;
								_u = prev[_u];
								_v = temp;
							}
							cout << endl;
						}
					}
				}
			}
		}
		if(matching[i] != -1) ++ans;
	}

	return ans;
}

int main()
{
//* test example1
	Edge edge1(1, 7, 0);
	Edge edge2(1, 8, 0);
	Edge edge3(1, 10, 0);
	Edge edge4(2, 8, 0);
	Edge edge5(2, 12, 0);
	Edge edge6(3, 8, 0);
	Edge edge7(3, 9, 0);
	Edge edge8(4, 9, 0);
	Edge edge9(4, 11, 0);
	Edge edge10(4, 12, 0);
	Edge edge11(5, 9, 0);
	Edge edge12(5, 10, 0);
	Edge edge13(5, 11, 0);
	Edge edge14(5, 12, 0);
	Edge edge15(6, 8, 0);
	Edge edge16(6, 11, 0);

	edges = {edge1, edge2, edge3, edge4,
	edge5, edge6, edge7, edge8,
	edge9, edge10, edge11, edge12,
	edge13, edge14, edge15, edge16
	};

	G[1] = {0, 1, 2};
	G[2] = {3, 4};
	G[3] = {5, 6};
	G[4] = {7, 8, 9};
	G[5] = {10, 11, 12, 13};
	G[6] = {14, 15};
	//*/
	/* test example2
	Edge edge1(1, 8, 0);
	Edge edge2(1, 10, 0);
	Edge edge3(2, 7, 0);
	Edge edge4(2, 8, 0);
	Edge edge5(2, 9, 0);
	Edge edge6(3, 9, 0);
	Edge edge7(3, 10, 0);
	Edge edge8(3, 11, 0);
	Edge edge9(3, 12, 0);
	Edge edge10(4, 9, 0);
	Edge edge11(4, 11, 0);
	Edge edge12(5, 8, 0);
	Edge edge13(5, 10, 0);
	Edge edge14(6, 11, 0);

	edges = { edge1, edge2, edge3, edge4,
		edge5, edge6, edge7, edge8,
		edge9, edge10, edge11, edge12,
		edge13, edge14
	};

	G[1] = { 0, 1 };
	G[2] = { 2, 3, 4 };
	G[3] = { 5, 6, 7, 8 };
	G[4] = { 9, 10 };
	G[5] = { 11, 12 };
	G[6] = { 13 };
*/
	/* test example3
	Edge edge1(1, 5, 0);
	Edge edge2(1, 6, 0);
	Edge edge3(1, 8, 0);
	Edge edge4(2, 6, 0);
	Edge edge5(2, 7, 0);
	Edge edge6(3, 7, 0);
	Edge edge7(4, 7, 0);


	edges = { edge1, edge2, edge3, edge4,
		edge5, edge6, edge7
	};

	G[1] = {0, 1, 2};
	G[2] = {3, 4 };
	G[3] = {5};
	G[4] = {6};
//*/
	int maxMatch = Hungarian();

	cout << "====== Matching Point Pair ======" << endl;
	for(int i = 1; i <= maxMatch; ++i)
	{
		cout << i << ": " << matching[i] << endl;
	}

	cout << "Max Matching: " << maxMatch << endl;

	return 0;
}
