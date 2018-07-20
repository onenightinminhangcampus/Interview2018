#include "stdafx.h"
#include <corecrt_malloc.h>
#include <ostream>
#include <iostream>

struct Node {
	int val;
	Node* next;
};

typedef Node* List;

List insertNode(List plist, int val)
{
	List p = (List)malloc(sizeof(Node));
	p->val = val;
	p->next = NULL;

	if(plist==NULL)
	{
		plist = p;
	} else
	{
		List q = plist;
		while(q->next)
		{
			q = q->next;
		}
		q->next = p;
	}
	return plist;
}

void printList(List plist)
{
	while(plist)
	{
		std::cout << plist->val << std::endl;
		plist = plist->next;
	}
}

//Remove duplicated node with identical value for a sorted node list
List removeDuplicate(List plist)
{
	List p1 = plist;
	while(p1 && p1->next)
	{
		while(p1->next && p1->val==p1->next->val)
		{
			p1->next = p1->next->next;
		}
		p1 = p1->next;
	}
		return plist;
}

int main()
{
	List plist = NULL;
	plist = insertNode(plist, 1);
	plist = insertNode(plist, 2);
	plist = insertNode(plist, 2);
	plist = insertNode(plist, 3);
	plist = insertNode(plist, 3);
	plist = insertNode(plist, 3);
	plist = insertNode(plist, 4);
	plist = insertNode(plist, 4);
	plist = insertNode(plist, 5);
	plist = insertNode(plist, 5);

	printList(plist);

	plist=removeDuplicate(plist);
	printList(plist);

	std::cin.get();

    return 0;
}

