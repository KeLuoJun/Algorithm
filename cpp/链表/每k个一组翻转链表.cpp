#include <iostream>
using namespace std;

typedef struct Node
{
	int data;
	struct Node *next;
}Node,*LinkNode;

// ��ǰ��Ŀ�ʼ�ڵ���s��������k���ҵ���ǰ��Ľ����ڵ㲢���� 
LinkNode teamEnd(LinkNode s,int k) 
{
	while(--k != 0 && s != NULL)
	{
		s = s->next;
	}
	return s;
}

//��ת���� 
void reverse(LinkNode &s,LinkNode &e)
{
	e = e->next;
	LinkNode pre = NULL,cur = s,next = NULL;
	while(cur != e)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	s->next = e;  //s��Ϊβ�ڵ� 
}

LinkNode reverKGroup(ListNode &head, int k)
{
	LinkNode start = head;
	LinkNode end = teamEnd(start,k);
	if(end == NULL)
		return head;
	//��һ������⣬��Ϊǣ������ͷ����
	head = end;
	reverse(start,end);
	//��ת֮��start�������һ��Ľ�β�ڵ�
	LinkNode lastTeamEnd = start;
	while(lastTeamEnd->next != NULL)
	{
		start = lastTeamEnd->next;
		end = teamEnd(start,k);
		//���鲻��k�� 
		if(end == NULL)
			return head;
		reverse(start,end);
		lastTeamEnd->next = end;
		lastTeamEnd = start; 
	 } 
	return head;
}
