#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode  
{
	ElemType data;
	struct LNode *next;		// 指向后继结点
} LinkNode;					// 声明单链表结点类型


// 尾插法建立单链表
void CreateListR(LinkNode *&L, ElemType a[], int n)
{
	// 尾插法代码已完成，直接调用即可
	LinkNode *s,*r;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	// 创建头结点
	L->next=NULL;
	r=L;					// r始终指向终端结点,开始时指向头结点
	for (int i=0;i<n;i++)
	{	
		s=(LinkNode *)malloc(sizeof(LinkNode));// 创建新结点s
		s->data=a[i];
		r->next=s;			// 将结点s插入结点r之后
		r=s;
	}
	r->next=NULL;			// 终端结点next域置为NULL
}

// 输出链表中的数据
void DispList(LinkNode *L)
{
	L = L->next;
	while (L!=NULL)
	{	
		printf("%d ",L->data);
		L=L->next;
	}
}

void GetElem(LinkNode *L, int i)
{
	// 请补充下面代码
	int flag = 0;
	int num = 0;
	L = L->next;
	while(L)
	{
		++num;
	    if(num == i)
	    {
	        flag = 1;
	        break;
	    }
	    L = L->next; 

	}
	if(flag)
	    printf("%d\n",L->data);
	else
	    printf("false\n");
}


void LocateElem(LinkNode *L, ElemType e)
{
	// 请补充下面代码
	int flag = 0;
	int num = 0;
	L = L->next;
	while(L)
	{
	    num++;
	    if(L->data == e)
	    {
	        flag = 1;
	        break;
	    }
	    L = L->next;
	}
	if(flag)
	    printf("%d\n",num);
	else
	    printf("0\n");
}


void ListInsert(LinkNode *&L,int i,ElemType e)
{
	// 请补充下面代码
	int flag = 0;
	int num = 0;
	LinkNode *pre = L;
	LNode *s;
	s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	while(pre)
	{
	    num++;
	    if(num == i)
	    {
	        s->next = pre->next;
	        pre->next = s;
	        flag = 1;
	        DispList(L);
	        printf("\n");
	        break;
	    }
	    pre = pre->next;
	}
	if(!flag)
	    printf("false\n");
	s = NULL;
}


void ListDelete(LinkNode *&L, int i)
{
	// 请补充下面代码
    int num = 1;
    int flag = 0;
    LinkNode *p = L,*q;
    while(p && num < i)
    {
        p = p->next;
        num++;
    }
    
    if(!p || num > i)
        printf("false\n");
    else 
    {
    	q = p->next;
    	p->next = q->next;
    	DispList(L);
	}
	free(q);
}



int main()
{
	int i = 0, n, data, getLocation, dataLocation;
	int insertLocation, insertData;
	int delLocation, delData;
	
	ElemType e;
	scanf("%d", &n);
	ElemType a[51];
	
	// 输入原始数据
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	// 查找指定位置 getLocation 的数据
	scanf("%d", &getLocation);
	
	// 查找指定数据 dataLocation 的位置
	scanf("%d", &dataLocation);
	
	// 在指定位置 insertLocation，插入指定数据 insertData
	scanf("%d %d", &insertLocation, &insertData);
	
	// 删除指定位置 delLocation 的数据
	scanf("%d", &delLocation);
	
	LinkNode *L;
	CreateListR(L,a,n);
	// 请补充下面代码
	// 请按输出要求补充【5】处的函数调用。
	// 先创建链接，再依次执行各种操作。
    DispList(L);
    printf("\n");
    GetElem(L,getLocation);
    LocateElem(L,dataLocation);
    ListInsert(L,insertLocation,insertData);
    ListDelete(L,delLocation);
	return 0;
}
