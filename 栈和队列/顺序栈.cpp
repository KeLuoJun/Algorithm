#include <iostream>
using namespace std;
const int MAXSIZE = 1000;
//顺序栈的定义
typedef struct
{
	int data[MAXSIZE];
	int top = -1;
}SqStack;

//进栈操作
bool Push(SqStack *S, int e)
{
	if(S->top == MAXSIZE - 1)
		return false;
	S->data[++S->top] = e;
	return true;	
} 

//出栈操作
bool Pop(SqStack *S, int *e)
{
	if(S->top == -1)
		return false;
	*e = S->data[S->top--];
	return true;
} 

//显示栈中的数据
void ShowStack(SqStack S)
{
	if(S.top == -1)
	{
		cout << "该栈为空栈" << endl;
		return;	
	}	
	while(S.top != -1)
	{
		cout << S.data[S.top--] << " ";
	}
}

void test()
{
	SqStack S;
	Push(&S, 1);
	Push(&S, 2);
	Push(&S, 3);
	int e;
	Pop(&S, &e);
	cout << e << endl;
	ShowStack(S);
}

int main()
{
	test();
	system("pause");
	return 0;
}
