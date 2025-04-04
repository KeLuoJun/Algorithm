#include <stdio.h>  
#include <stdlib.h> // Ϊ��ʹ��free()  
  
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
    if (!L) { // ����ڴ��Ƿ�ɹ�����  
        printf("Memory allocation failed!\n");  
        exit(1); // �˳�����  
    }  
    for (int i = 0; i < n; i++)  
        L->data[i] = a[i];  
    L->length = n;  
}  
  
void DispList(SqList *L)  
{  
    for (int i = 0;i < L->length; i++)  
        printf("%d ", L->data[i]);  
    printf("\n"); // �������������ӻ��з���ʹ���������  
}  
  
bool ListInsert(SqList *&L,int i,ElemType e)  
{  
    if (i < 0 || i > L->length) { // ��������Ƿ�Խ��  
        printf("Index out of bounds!\n");  
        return false; // ����false��ʾ����ʧ��  
    }  
    L->length++;  
    for(int j = L->length-2; j >= i; j--) // �Ӻ���ǰ�ƶ�Ԫ�أ�ֱ������λ�õ�ǰһ��λ��  
        L->data[j+1] = L->data[j]; // ע��������j+1����Ϊj��L->length-2��ʼ������j+1����Խ��  
    L->data[i] = e; // ��ָ��λ�ò�����Ԫ��  
    return true; // ����true��ʾ����ɹ�  
}  
  
int main()  
{  
    int i, n, p, d;  
    scanf("%d", &n);  
    ElemType a[51]; // �޸������СΪ51��ƥ������������ݺʹ����߼�  
    for(i = 0; i < n; i++)  
    {  
        scanf("%d", &a[i]);  
    }  
    // ���� p �� d ������  
    scanf("%d%d",&p,&d);  
    SqList *L;  
    CreateList(L, a, n);  
    // �������ݲ�����Ƿ�ɹ�����  
    if (!ListInsert(L,p-1,d)) {  
         // �������ʧ�ܣ����������Ϣ���˳����򣨿�ѡ��  
        exit(1); // �˳����򣨿�ѡ��  
    }  
    DispList(L);
    return 0;
}
