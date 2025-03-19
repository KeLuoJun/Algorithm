#include <stdio.h>
#include <math.h>
int main()
{
    int n,t1,t2;
    int num[100];
	int a[100];
    while(scanf("%d",&n), n != 0)
    {
        for(int i = 0; i < n; i++)
        {   scanf("%d",&num[i]);
            a[i] = abs(num[i]);
        }
        for(int i = 0; i < n-1; i++)
            for(int j = 0; j < n-i-1; j++)
            {
                if(a[j] < a[j+1])
                {
                    t1 = num[j];
                    num[j] = num[j+1];
                    num[j+1] = t1;
                    t2 = a[j];
                    a[j] = a[j+1];
                    a[j+1] = t2;
                }
            }
        for(int i = 0; i < n; i++)
            printf("%d ",num[i]);
        printf("\n");
        
    }
    return 0;
}
