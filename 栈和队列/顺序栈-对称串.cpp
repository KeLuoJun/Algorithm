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
    int top;    // 栈指针
}SqStack;      // 顺序栈类型

// 初始化栈
void InitStack(SqStack *&s)
{
    // 补充下面的代码
    s = new SqStack;
    s->top = -1;
}

// 销毁栈
void DestroyStack(SqStack *&s)
{
    // 补充下面的代码
    delete s;
}

// 入栈
bool Push(SqStack *&s,ElemType e)
{
    // 补充下面的代码
    if(s->top == MaxSize-1)
        return false;
    s->data[++s->top] = e;
//    cout << s->top;
//    cout << s->data[++s->top];
    return true;
}

// 出栈
bool Pop(SqStack *&s,ElemType &e)
{
    // 补充下面的代码
    if(s->top == -1)
        return false;
    e = s->data[s->top--];
    return true;
}

// 判断对称串
bool symmetry(SqStack *s,ElemType str[])
{
    // 补充下面的代码
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
	
    cin >> str;     // 输入字符串
	
    // 补充下面的代码
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
