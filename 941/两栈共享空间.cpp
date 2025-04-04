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
	cout << "****����ѡ��****" << endl;
	cout << "A. ��ջ" << endl;
	cout << "B. ��ջ" << endl;
	cout << "C. ��ʾջ�е�����" << endl;
	cout << "D. �˳�����" << endl;
}

bool Push(SqDoubleStack *S, int e, int stackNumber)
{
	if(S->top1 + 1 == S->top2)
	{
		cout << "ջ1��������ջʧ��" << endl;
		return false;
	}
		
	if(stackNumber == 1)
		S->data[++S->top1] = e;
	else if(stackNumber == 2)
		S->data[--S->top2] = e;
	cout << "��ջ�ɹ�" << endl;
	return true;
}

bool Pop(SqDoubleStack *S, int *e, int stackNumber)
{
	if(stackNumber == 1)
	{
		if(S->top1 == -1)
		{
			cout << "ջ1Ϊ�գ���ջʧ��" << endl;
			return false;
		}		
		*e = S->data[S->top1--];
	}
	else if(stackNumber == 2)
	{
		if(S->top2 == MAXSIZE)
		{
			cout << "ջ1Ϊ�գ���ջʧ��" << endl;
			return false;
		}	
		*e = S->data[S->top2++];
	}
	cout << "��ջ�ɹ�" << endl;
	return true;
}

void ShowStack(SqDoubleStack *S)
{
	if(S->top1 == -1)
		cout << "ջ1Ϊ��" << endl;
	else
	{
		for(int i = 0; i <= S->top1; i++)
			cout << S->data[i] << " "; 
		cout << endl;
	}
	
	if(S->top2 == MAXSIZE)
		cout << "ջ2Ϊ��" << endl;
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
	S = new SqDoubleStack;  //�ص� 
	char choice;
	int e,stackNumber;
	while(true)
	{
		menu();
		cin >> choice;
		switch(choice)
		{
			case 'A':
				cout << "������Ҫ��ջ��Ԫ�أ�";
				cin >> e;
				cout << "������Ҫ�����ջ����1/2����";
				cin >> stackNumber;
				Push(S, e, stackNumber);
				break;
			case 'B':
				cout << "������Ҫ������ջ����1/2����";
				cin >> stackNumber;
				Pop(S, &e, stackNumber);
				cout << "������Ԫ�أ�" << e << endl;
				break;
			case 'C':
				ShowStack(S);
				break;
			case 'D':
				return 0;
			default:
				cout << "����������������룡" << endl; 
		}
		system("pause");
		system("cls");
	}
	return 0;
}
