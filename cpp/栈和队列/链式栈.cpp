#include <iostream>
using namespace std;

//��ջ�Ķ���
//ջ��Ϊ�����յ�ջ�� 
typedef struct StackNode
{
	int data;
	struct StackNode *next; 	
}StackNode, LinkStackPtr;
typedef struct
{
	LinkStackPtr *top;
	int count;
}LinkStack;


//��ջ
bool Push(LinkStack *&S, int e)
{
	LinkStackPtr *s = new StackNode;
	s->data = e;
	s->next = S->top;
	S->top = s;
	S->count++;
	return true; 
} 

//��ջ
bool Pop(LinkStack *&S, int *e)
{
	LinkStackPtr *p;
	if(S->top == NULL)
		return false;
		
	*e = S->top->data;
	p = S->top;
	S->top = S->top->next;
	S->count--;
	return true;
 } 
 
//��ʾջ�е�����
void ShowStack(LinkStack *S)
{
	if(S->top == NULL)
	{
		cout << "��ջΪ��" << endl;
		return;
	}
	cout << "ջ�е������У�������" << S->count << endl;
	while(S->top != NULL)
	{
		cout << S->top->data << " ";
		S->top = S->top->next;
	}
 } 
 
void test()
{
	LinkStack *S;
	S = new LinkStack;
	S->count = 0;
	S->top = NULL;
	int e;
	Push(S, 1);
	Push(S, 2);
	Push(S, 3);
	Pop(S,&e);
	cout << "��ջ������Ϊ�� " << e << endl;
	ShowStack(S);
}

int main()
{
	test();
	system("pause");
	return 0;
}
