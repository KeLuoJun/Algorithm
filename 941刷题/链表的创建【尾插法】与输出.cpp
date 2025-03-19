#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode  
{
	ElemType data;
	struct LNode *next;		//ָ���̽��
} LinkNode;					//����������������


// β�巨����������
void CreateListR(LinkNode *&L, ElemType a[], int n)
{
	// ��������Ĵ���
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

// ��������е�����
void DispList(LinkNode *L)
{
    // ��������Ĵ���
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
    L->data = a[0];  //����ͷ��� 
    // ��������Ĵ���
    CreateListR(L,a,n);
    
    // ��������Ĵ���
    DispList(L);
    
    return 0;
}
