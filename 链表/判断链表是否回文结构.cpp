#include <iostream>
using namespace std;
#define Element int
//��ͷ��� 
typedef struct Node
{
	Element data;
	Node *next;
}Node,*LinkNode;

bool isPalindrome(LinkNode &head)
{
	if(head == NULL || head->next == NULL)
		return true;
	//���е�
	LinkNode slow = head,fast = head;
	while(fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	
	//����slow�����е㣬���е㿪ʼ����Ľڵ�����
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
	//����Ĺ����Ѿ�����������ɴ������������м�ָ
	// head -> ... -> slow <- ... <- pre 
	bool ans = true;
	LinkNode left = head;
	LinkNode right = pre;
	//left���ҡ�right����ÿһ���ȶ�ֵ�Ƿ���ȣ����ĳһ����һ���𰸾���false 
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
	
	//�����������ԭ���������ٷ����жϽ��
	cur = pre->next;
	pre->next = NULL;
	next = NULL;
	while(cur != NULL)
	{
		//next���ڴ洢����ǰcur->next�ĵ�ַ����ֹcur->next��ַ�޸ĺ��Ҳ���cur��ǰһ���ڵ� 
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return ans; 
}	
