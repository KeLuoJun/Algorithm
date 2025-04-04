#include <iostream>
using namespace std;
const int MAXSIZE = 50;
typedef struct
{
	int data[MAXSIZE];
	int top1 = -1;
	int top2 = MAXSIZE;
}SqDoubleStack;

void menu()
{
	cout << "****************" << endl;
	cout << "****功能选项****" << endl;
	cout << "A. 进栈" << endl;
	cout << "B. 出栈" << endl;
	cout << "C. 显示栈中的数据" << endl;
	cout << "D. 退出程序" << endl;
}

bool Push(SqDoubleStack *S, int e, int stackNumber)
{
	if(S->top1 + 1 == S->top2)
	{
		cout << "栈1已满，进栈失败" << endl;
		return false;
	}
		
	if(stackNumber == 1)
		S->data[++S->top1] = e;
	else if(stackNumber == 2)
		S->data[--S->top2] = e;
	cout << "进栈成功" << endl;
	return true;
}

bool Pop(SqDoubleStack *S, int *e, int stackNumber)
{
	if(stackNumber == 1)
	{
		if(S->top1 == -1)
		{
			cout << "栈1为空，出栈失败" << endl;
			return false;
		}		
		*e = S->data[S->top1--];
	}
	else if(stackNumber == 2)
	{
		if(S->top2 == MAXSIZE)
		{
			cout << "栈1为空，出栈失败" << endl;
			return false;
		}	
		*e = S->data[S->top2++];
	}
	cout << "出栈成功" << endl;
	return true;
}

void ShowStack(SqDoubleStack *S)
{
	if(S->top1 == -1)
		cout << "栈1为空" << endl;
	else
	{
		for(int i = 0; i <= S->top1; i++)
			cout << S->data[i] << " "; 
		cout << endl;
	}
	
	if(S->top2 == MAXSIZE)
		cout << "栈2为空" << endl;
	else
	{
		for(int i = MAXSIZE-1; i >= S->top2; i--)
			cout << S->data[i] << " ";
		cout << endl;
	}
}

int main()
{
	SqDoubleStack *S;
	S = new SqDoubleStack;  //重点 
	char choice;
	int e,stackNumber;
	while(true)
	{
		menu();
		cin >> choice;
		switch(choice)
		{
			case 'A':
				cout << "请输入要进栈的元素：";
				cin >> e;
				cout << "请输入要进入的栈区（1/2）：";
				cin >> stackNumber;
				Push(S, e, stackNumber);
				break;
			case 'B':
				cout << "请输入要弹出的栈区（1/2）：";
				cin >> stackNumber;
				Pop(S, &e, stackNumber);
				cout << "弹出的元素：" << e << endl;
				break;
			case 'C':
				ShowStack(S);
				break;
			case 'D':
				return 0;
			default:
				cout << "输入错误，请重新输入！" << endl; 
		}
		system("pause");
		system("cls");
	}
	return 0;
}
