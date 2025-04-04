#include <stdio.h>
int main()
{
    int a[40];
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    for(int i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");
    
    for(int i = 0; i < n-1; i++)
    {
        int t = a[0];
        for(int j = 0; j < n; j++)
        {
            
            if(j == n-1)
                a[j] = t;
            else
            	a[j] = a[j+1];
        }
        for(int k = 0; k < n; k++)
            printf("%d ",a[k]);
        printf("\n");
    }
    return 0;
}
