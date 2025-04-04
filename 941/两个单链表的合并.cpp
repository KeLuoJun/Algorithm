#include "iostream"
#include "stdlib.h"
using namespace std;
typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node,LinkNode;

//链表的输出
void ShowLinkNode(LinkNode *L)
{
	L = L->next;
	while(L != NULL)
	{
		cout << L->data << " ";
		L= L->next;
	}
	cout << endl;
}

//创建链表 
void CreatLinkNode(LinkNode *&L,int a[],int n)
{
	L = new LinkNode;
	L->next = NULL;
	//尾插法
	Node *r,*s;
	r = L;
	for(int i = 0; i < n; i++)
	{
		s = new Node;
		s->data = a[i];
		s->next = r->next;
		r->next = s;
	}
	r->next = NULL;
	ShowLinkNode(L);
}

//合并链表 
void MergeLinkNode(LinkNode *&L,LinkNode *L1,LinkNode *L2)
{
	L = new LinkNode;
	Node *p1 = L1->next;
	Node *p2 = L2->next;
	Node *pre = L;
	while(p1 != NULL && p2 != NULL)
	{
		if(p1->data <= p2->data)
		{
			pre->next = p1;
			p1 = p1->next;
		}
		else
		{
			pre->next = p2;
			p2 = p2->next;
		}
		pre = pre->next;
	}
	pre->next = p1 == NULL ? p2 : p1;
	while (pre->next != NULL)
    {
        pre = pre->next;
    }

    // 设置最后一个节点的 next 为 NULL
    pre->next = NULL;

	ShowLinkNode(L);
}



int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	int *b = new int[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
		
	LinkNode *L1,*L2,*L;
	CreatLinkNode(L1,a,n);
	CreatLinkNode(L2,b,n);
	MergeLinkNode(L,L1,L2);
	delete []a;
	delete []b;
	return 0;
}
