#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[50000];
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    //Ã°ÅÝÅÅÐò£¨ÉýÐò£©
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                int t = a[j+1];
                a[j+1] = a[j];
                a[j] = t;
            }
        }
    int count = 1,max = 0,num = a[0];
    int p1 = 0,p2 = 1;
    while(p2 < n)
    {
        if(a[p1] == a[p2])
        {
            count++;
        }
        else
        {
            if(count > max)
            {
                max = count;
                num = a[p1];
            }
            p1 = p2;
            count = 1;
        }
        p2++;
    }
    printf("%d\n%d\n",num,max);
    return 0;
}

