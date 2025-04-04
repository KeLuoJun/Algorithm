//��ͷ��� 
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode  
{
	ElemType data;
	struct LNode *next;		//ָ���̽��
} LinkNode;					//����������������

void CreateListF(LinkNode *&L, ElemType a[], int n)
//ͷ�巨����������
{
	// ��������Ĵ���
	LinkNode *s;
	for(int i = 0; i < n; i++)
	{
	    s = (LinkNode *)malloc(sizeof(LinkNode));
	    s->data = a[i];
	    s->next = L->next;
	    L->next = s;
	}
}

// ��������е�����
void DispList(LinkNode *L)
{
    // ��������Ĵ���
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
    
    LinkNode *L = (LinkNode *)malloc(sizeof(LinkNode)); // ��ʼ��ͷ��㲢�����ڴ�  
    L->next = NULL;
    // ��������Ĵ���
    CreateListF(L,a,n);
    
    // ��������Ĵ���
    DispList(L);
    free(L);
    return 0;
}
