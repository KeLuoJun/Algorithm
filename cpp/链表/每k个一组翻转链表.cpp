#include <iostream>
using namespace std;

typedef struct Node
{
	int data;
	struct Node *next;
}Node,*LinkNode;

// 当前组的开始节点是s，往下数k个找到当前组的结束节点并返回 
LinkNode teamEnd(LinkNode s,int k) 
{
	while(--k != 0 && s != NULL)
	{
		s = s->next;
	}
	return s;
}

//翻转操作 
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
	s->next = e;  //s变为尾节点 
}

LinkNode reverKGroup(ListNode &head, int k)
{
	LinkNode start = head;
	LinkNode end = teamEnd(start,k);
	if(end == NULL)
		return head;
	//第一组很特殊，因为牵扯到换头问题
	head = end;
	reverse(start,end);
	//翻转之后start变成了上一组的结尾节点
	LinkNode lastTeamEnd = start;
	while(lastTeamEnd->next != NULL)
	{
		start = lastTeamEnd->next;
		end = teamEnd(start,k);
		//该组不够k个 
		if(end == NULL)
			return head;
		reverse(start,end);
		lastTeamEnd->next = end;
		lastTeamEnd = start; 
	 } 
	return head;
}
