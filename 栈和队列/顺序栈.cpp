#include <iostream>
using namespace std;
const int MAXSIZE = 1000;
//˳��ջ�Ķ���
typedef struct
{
	int data[MAXSIZE];
	int top = -1;
}SqStack;

//��ջ����
bool Push(SqStack *S, int e)
{
	if(S->top == MAXSIZE - 1)
		return false;
	S->data[++S->top] = e;
	return true;	
} 

//��ջ����
bool Pop(SqStack *S, int *e)
{
	if(S->top == -1)
		return false;
	*e = S->data[S->top--];
	return true;
} 

//��ʾջ�е�����
void ShowStack(SqStack S)
{
	if(S.top == -1)
	{
		cout << "��ջΪ��ջ" << endl;
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
