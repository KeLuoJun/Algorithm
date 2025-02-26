#include <iostream>
using namespace std;
#define Element int
//无头结点 
typedef struct Node
{
	Element data;
	Node *next;
}Node,*LinkNode;

bool isPalindrome(LinkNode &head)
{
	if(head == NULL || head->next == NULL)
		return true;
	//找中点
	LinkNode slow = head,fast = head;
	while(fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	
	//现在slow就是中点，从中点开始往后的节点逆序
	LinkNode pre = slow;
	LinkNode cur = pre->next;
	LinkNode next = NULL;
	pre->next = NULL;
	while(cur != NULL)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	//上面的过程已经把链表调整成从左右两侧往中间指
	// head -> ... -> slow <- ... <- pre 
	bool ans = true;
	LinkNode left = head;
	LinkNode right = pre;
	//left往右、right往左，每一步比对值是否相等，如果某一步不一样答案就是false 
	while(left != NULL && right != NULL)
	{
		if(left->data != right->data)
		{
			ans = false;
			break;
		} 
		left = left->next;
		right = right->next;
	}
	
	//把链表调整成原来的样子再返回判断结果
	cur = pre->next;
	pre->next = NULL;
	next = NULL;
	while(cur != NULL)
	{
		//next用于存储逆序前cur->next的地址，防止cur->next地址修改后找不到cur的前一个节点 
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return ans; 
}	
