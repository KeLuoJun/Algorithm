#include <iostream>
using namespace std;

//链栈的定义
//栈底为单个空的栈点 
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


//进栈
bool Push(LinkStack *&S, int e)
{
	LinkStackPtr *s = new StackNode;
	s->data = e;
	s->next = S->top;
	S->top = s;
	S->count++;
	return true; 
} 

//出栈
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
 
//显示栈中的数据
void ShowStack(LinkStack *S)
{
	if(S->top == NULL)
	{
		cout << "该栈为空" << endl;
		return;
	}
	cout << "栈中的数据有（个）：" << S->count << endl;
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
	cout << "出栈的数据为： " << e << endl;
	ShowStack(S);
}

int main()
{
	test();
	system("pause");
	return 0;
}
