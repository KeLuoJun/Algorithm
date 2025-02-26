#include <iostream>
#include <math.h>
using namespace std;

typedef struct Node
{
	int data;
	struct Node *next;
}Node,*LinkNode;

LinkNode getIntersectionNode(LinkNode h1,LinkNode h2)
{
	if(h1->next == NULL || h2->next == NULL)
		return NULL;
	LinkNode a = h1,b = h2;   //a为长链表，b为短链表 
	int diff = 0;
	while(a->next != NULL)
	{
		a = a->next;
		diff++;
	}
	while(b->next != NULL)
	{
		b = b->next;
		diff--;
	}
	if(a != b)
		return NULL;
	if(diff >= 0)
	{
		a = h1;
		b = h2;
	}
	if(diff < 0)
	{
		a = h2;
		b = h1;
	}
	diff = abs(diff);
	while(diff-- != 0)
		a = a->next;
	while(a != b)
	{
		a = a->next;
		b = b->next;
	}
	return a;
}
