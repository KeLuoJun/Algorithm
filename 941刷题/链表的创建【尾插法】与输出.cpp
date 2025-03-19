#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode  
{
	ElemType data;
	struct LNode *next;		//指向后继结点
} LinkNode;					//声明单链表结点类型


// 尾插法建立单链表
void CreateListR(LinkNode *&L, ElemType a[], int n)
{
	// 补充下面的代码
	LinkNode *r = L,*s;
	for(int i = 1; i < n; i++)
	{
	    s = (LinkNode *)malloc(sizeof(LinkNode));
	    s->data = a[i];
	    r->next = s;
	    r = s;
	}
	r->next = NULL; 
}

// 输出链表中的数据
void DispList(LinkNode *L)
{
    // 补充下面的代码
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
    
    LinkNode *L = (LinkNode *)malloc(sizeof(LinkNode));
    L->data = a[0];  //不带头结点 
    // 补充下面的代码
    CreateListR(L,a,n);
    
    // 补充下面的代码
    DispList(L);
    
    return 0;
}
