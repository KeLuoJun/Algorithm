#include <iostream>
using namespace std;
#include <string>
#define MAXSIZE 10
typedef struct
{
    char data[MAXSIZE];
    int top;
}SqStack;

void InitStack(SqStack *&S)
{
    S = new SqStack;
    S->top = -1;
}

bool Push(SqStack *&S, char e)
{
    if(S->top == MAXSIZE - 1)
        return false;
    S->data[++S->top] = e;
    return true;
}

bool Pop(SqStack *&S, char *e)
{
    if(S->top == -1)
        return false;
    *e = S->data[S->top--];
    return true;
}

int main()
{
    int k;
    cin >> k;
    string s;
    char b;
    cin >> s;
    int sum = 0;
    for(int i = 0; i < s.size(); i++)
    {
        string a = s.substr(i,k);
        SqStack *S;
        InitStack(S);
        int start = i;
        string ans;
        for(int j = 0; j < k; j++)
        {
            Push(S,a[j]); 
        }
        while(Pop(S,&b))
        {
            ans += b;
        }
        if(ans == a)
            sum++;
        delete S;
    }
    cout << sum << endl;
    return 0;
}
