#include <stdio.h>
#include <malloc.h>
#define MaxSize 50
typedef int ElemType;

typedef struct 
{
    ElemType data[MaxSize];
    int length;
} SqList;

void CreateList(SqList *&L, ElemType a[],int n)
{
    L = (SqList *)malloc(sizeof(SqList));
    for(int i = 0; i < n; i++)
        L->data[i] = a[i];
    L->length = n;
}

void DispList(SqList *L)
{
    for(int i = 0; i < L->length; i++)
        printf("%d ",L->data[i]);
}

int main()
{
    int i, n;
    scanf("%d", &n);
    ElemType a[51];
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    SqList *L;
    // CreateList(L, a, n);
    CreateList(L,a,n);
    // DispList(L);
    DispList(L);
    return 0;
}
