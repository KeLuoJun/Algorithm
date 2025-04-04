#include <stdio.h>
int a[100][1000];
int main()
{
    void sort(int (*p),int n);
    int n;
    scanf("%d",&n);
    int num[100];
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&num[i]);
        for(int j = 0; j < num[i]; j++)
            scanf("%d",&a[i][j]);
        sort(a[i],num[i]);
        
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < num[i]; j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
        
}

void sort(int *p,int n)
{
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
        {
            if(p[j] > p[j+1])
            {
            	int t = p[j+1];
            	p[j+1] = p[j];
            	p[j] = t;
			}
        }
}
