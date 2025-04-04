//带头结点 
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode  
{
	ElemType data;
	struct LNode *next;		//指向后继结点
} LinkNode;					//声明单链表结点类型

void CreateListF(LinkNode *&L, ElemType a[], int n)
//头插法建立单链表
{
	// 补充下面的代码
	LinkNode *s;
	for(int i = 0; i < n; i++)
	{
	    s = (LinkNode *)malloc(sizeof(LinkNode));
	    s->data = a[i];
	    s->next = L->next;
	    L->next = s;
	}
}

// 输出链表中的数据
void DispList(LinkNode *L)
{
    // 补充下面的代码
    L = L->next;
    while(L)
    {
        printf("%d ",L->data);
        L = L->next;
    }
}

int main()
{
    int i = 0, n, data;
    scanf("%d", &n);
    ElemType a[51];
    
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    LinkNode *L = (LinkNode *)malloc(sizeof(LinkNode)); // 初始化头结点并分配内存  
    L->next = NULL;
    // 补充下面的代码
    CreateListF(L,a,n);
    
    // 补充下面的代码
    DispList(L);
    free(L);
    return 0;
}
