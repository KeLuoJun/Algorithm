#include <stdio.h>  
#include <stdlib.h> // 为了使用free()  
  
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
    if (!L) { // 检查内存是否成功分配  
        printf("Memory allocation failed!\n");  
        exit(1); // 退出程序  
    }  
    for (int i = 0; i < n; i++)  
        L->data[i] = a[i];  
    L->length = n;  
}  
  
void DispList(SqList *L)  
{  
    for (int i = 0;i < L->length; i++)  
        printf("%d ", L->data[i]);  
    printf("\n"); // 在输出结束后添加换行符，使输出更清晰  
}  
  
bool ListInsert(SqList *&L,int i,ElemType e)  
{  
    if (i < 0 || i > L->length) { // 检查索引是否越界  
        printf("Index out of bounds!\n");  
        return false; // 返回false表示插入失败  
    }  
    L->length++;  
    for(int j = L->length-2; j >= i; j--) // 从后向前移动元素，直到插入位置的前一个位置  
        L->data[j+1] = L->data[j]; // 注意这里是j+1，因为j从L->length-2开始，所以j+1不会越界  
    L->data[i] = e; // 在指定位置插入新元素  
    return true; // 返回true表示插入成功  
}  
  
int main()  
{  
    int i, n, p, d;  
    scanf("%d", &n);  
    ElemType a[51]; // 修改数组大小为51以匹配你的输入数据和代码逻辑  
    for(i = 0; i < n; i++)  
    {  
        scanf("%d", &a[i]);  
    }  
    // 输入 p 与 d 的数据  
    scanf("%d%d",&p,&d);  
    SqList *L;  
    CreateList(L, a, n);  
    // 插入数据并检查是否成功插入  
    if (!ListInsert(L,p-1,d)) {  
         // 如果插入失败，输出错误信息并退出程序（可选）  
        exit(1); // 退出程序（可选）  
    }  
    DispList(L);
    return 0;
}
