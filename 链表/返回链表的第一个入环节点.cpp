//����
//��ָ��ÿ������������ָ��ÿ����һ��
//������ָ���һ��������
//��ָ��ص���ͷ�ڵ�
//��ָ��ÿ����һ������ָ��ÿ����һ��
//�ٴ�������Ϊ�뻷�׽ڵ� 

#include <iostream>
using namespace std;
#define Element int
//��ͷ��� 
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

