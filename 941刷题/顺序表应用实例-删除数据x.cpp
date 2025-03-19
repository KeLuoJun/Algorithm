#include <stdio.h>
#include <malloc.h>

#define MaxSize 50
typedef int ElemType;

typedef struct 
{
    ElemType data[MaxSize];
    int length;
} SqList;

void CreateList(SqList *&L, ElemType a[], int n)
{
    L = (SqList *)malloc(sizeof(SqList));
    for (int i = 0; i < n; i++)
        L->data[i] = a[i];
    L->length = n;
}

void DispList(SqList *L)
{
    for (int i = 0;i < L->length; i++)
        printf("%d ", L->data[i]);
}

void delnode1(SqList *&L, ElemType x)
{
    for(int i = 0; i < L->length; i++)
    {
        if(L->data[i] == x)
        {
            L->length--;
            for(int j = i; j < L->length; j++)
                L->data[j] = L->data[j+1];
            i--;
        } 
    }
}

int main()
{
    int n,x;
    ElemType a[51];
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    scanf("%d",&x);
    SqList *L;
    CreateList(L,a,n);
    delnode1(L,x);
    DispList(L);
    return 0;
}
