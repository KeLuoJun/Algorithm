#include <stdio.h>
#include <malloc.h>
#include <string>
#include <iostream>

using namespace std;

#define MaxSize 100

typedef char ElemType;

typedef struct 
{	
    ElemType data[MaxSize];
    int top;    // ջָ��
}SqStack;      // ˳��ջ����

// ��ʼ��ջ
void InitStack(SqStack *&s)
{
    // ��������Ĵ���
    s = new SqStack;
    s->top = -1;
}

// ����ջ
void DestroyStack(SqStack *&s)
{
    // ��������Ĵ���
    delete s;
}

// ��ջ
bool Push(SqStack *&s,ElemType e)
{
    // ��������Ĵ���
    if(s->top == MaxSize-1)
        return false;
    s->data[++s->top] = e;
//    cout << s->top;
//    cout << s->data[++s->top];
    return true;
}

// ��ջ
bool Pop(SqStack *&s,ElemType &e)
{
    // ��������Ĵ���
    if(s->top == -1)
        return false;
    e = s->data[s->top--];
    return true;
}

// �ж϶Գƴ�
bool symmetry(SqStack *s,ElemType str[])
{
    // ��������Ĵ���
    if(s->top == -1 || s->top == 0)
        return true;
    int i = 0;
    ElemType e;
    while(Pop(s,e))
    {
        if(e != str[i])
            return false;
        i++;
    }
    return true; 
}

int main()
{
    ElemType str[51];
	
    cin >> str;     // �����ַ���
	
    // ��������Ĵ���
    SqStack *s;
    InitStack(s);
    int len = 0;
    while(str[len] != '\0')
    	len++;
    for(int i = 0; i < len; i++)
        Push(s,str[i]);
    if(symmetry(s,str))
        cout << "true" << endl;
    else
        cout << "false" << endl;
	DestroyStack(s);
    return 0;
}
