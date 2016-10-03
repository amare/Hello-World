//
// @file:           RemoCycleFList.cpp
// @author:         cuckoo
// @date:           2016/10/02 21:17:12
// @description:    Create and Remove Cycle in a forward list, see http://blog.jobbole.com/106227/
// @note
//

#include <iostream>
#include <set>

typedef struct Node
{
	int ID;
	Node *pNext;
}Node, *pNode;

void OutputCyclicList(pNode head, int length)
{
	pNode pTail = head;
	int circle = length + 3;
	while(pTail != NULL && --circle)
	{
		std::cout << pTail->ID << "\t" << pTail->pNext << std::endl;
		pTail = pTail->pNext;
	}
}

void GeneCyclicList(pNode head, int length, int startPos)
{
	// no cycle
	pNode pTail = head;
	for(int i = 1; i <= length; ++i)
	{
		pNode newNode = new Node();

		newNode->ID = i;
		newNode->pNext = NULL;

		pTail->pNext = newNode;
		pTail = newNode;
	}

	OutputCyclicList(head, length);

	//generate cycle
	pNode pStart = head;
	while(startPos--)
	{
		pStart = pStart->pNext;
	}
	pTail->pNext = pStart;

	std::cout << "\n======== after generate cycle ========" << std::endl;
	OutputCyclicList(head, length);

}

void RemoveCycle(pNode head, int length)
{
	// remove cyclic
	std::set<int> iset;
	pNode pPre = head;
	pNode pNow = head->pNext;
	while(pNow)
	{
		if(iset.find(pNow->ID) == iset.end())
		{
			iset.insert(pNow->ID);
		}
		else
		{
			std::cout << "\nDetect Cycle, Start Position: " << pNow->ID << std::endl;
			pPre->pNext = NULL;
			break;
		}
		pPre = pNow;
		pNow = pNow->pNext;
	}

	std::cout << "\n======== after remove cycle ========" << std::endl;
	OutputCyclicList(head, length);
}

void DestroyList(pNode head)
{
	// destroy the acyclic list
	pNode temp;
	while(head)
	{
		temp = head->pNext;
		delete head;
		head = temp;
	}
}

int main()
{
	int length, startPos;
	std::cout << "Input the length of List, and then cycle start position: " << std::endl;
	std::cin >> length >> startPos;
	if(startPos > length)
	{
		std::cout << "startPos is bigger than length of the list, re-input startPos:" << std::endl;
		std::cin >> startPos;
	}

	pNode head = new Node();
	std::cout << "head:\t" << head << std::endl;

	GeneCyclicList(head, length, startPos);

	RemoveCycle(head, length);

	DestroyList(head);

	return 0;
}
