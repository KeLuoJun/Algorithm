//结论
//快指针每次走两步，慢指针每次走一步
//当快慢指针第一次相遇后
//快指针回到开头节点
//快指针每次走一步，慢指针每次走一步
//再次相遇即为入环首节点 

#include <iostream>
using namespace std;
#define Element int
//无头结点 
typedef struct Node
{
	Element data;
	Node *next;
}Node,*LinkNode;

LinkNode detectCycle(LinkNode head)
{
	if(head == NULL || head->next == NULL || head->next->next == NULL)
	{
		return NULL;
	}
	LinkNode slow = head->next;
	LinkNode fast = head->next->next;
	while(fast != slow)
	{
		if(fast->next == NULL || fast->next->next)
			return NULL;
		slow = slow->next;
		fast = fast->next->next;
	 } 
	fast = head;
	while(fast != slow)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

