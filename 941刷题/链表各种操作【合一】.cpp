#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode  
{
	ElemType data;
	struct LNode *next;		// ָ���̽��
} LinkNode;					// ����������������


// β�巨����������
void CreateListR(LinkNode *&L, ElemType a[], int n)
{
	// β�巨��������ɣ�ֱ�ӵ��ü���
	LinkNode *s,*r;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	// ����ͷ���
	L->next=NULL;
	r=L;					// rʼ��ָ���ն˽��,��ʼʱָ��ͷ���
	for (int i=0;i<n;i++)
	{	
		s=(LinkNode *)malloc(sizeof(LinkNode));// �����½��s
		s->data=a[i];
		r->next=s;			// �����s������r֮��
		r=s;
	}
	r->next=NULL;			// �ն˽��next����ΪNULL
}

// ��������е�����
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
	// �벹���������
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
	// �벹���������
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
	// �벹���������
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
	// �벹���������
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
	
	// ����ԭʼ����
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	// ����ָ��λ�� getLocation ������
	scanf("%d", &getLocation);
	
	// ����ָ������ dataLocation ��λ��
	scanf("%d", &dataLocation);
	
	// ��ָ��λ�� insertLocation������ָ������ insertData
	scanf("%d %d", &insertLocation, &insertData);
	
	// ɾ��ָ��λ�� delLocation ������
	scanf("%d", &delLocation);
	
	LinkNode *L;
	CreateListR(L,a,n);
	// �벹���������
	// �밴���Ҫ�󲹳䡾5�����ĺ������á�
	// �ȴ������ӣ�������ִ�и��ֲ�����
    DispList(L);
    printf("\n");
    GetElem(L,getLocation);
    LocateElem(L,dataLocation);
    ListInsert(L,insertLocation,insertData);
    ListDelete(L,delLocation);
	return 0;
}
