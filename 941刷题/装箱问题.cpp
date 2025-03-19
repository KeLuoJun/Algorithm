
#include <stdio.h>
int main()
{
    int n,count,max = 0;
    scanf("%d",&n);
    int s[1001],v[1001];
    for(int i = 1; i <= n; i++)
    {
        v[i] = 100;
        scanf("%d",&s[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        count = 1;
        if(s[i] <= v[count])
        {
            printf("%d %d\n",s[i],count);
            v[count] -= s[i];
        }
        else
        {
            while(s[i] > v[count])
            {
                count++;
                if(s[i] <= v[count])
                {
                    v[count] -= s[i];
                    break;
                }
            }
            if(count > max)
                	max = count;
            printf("%d %d\n",s[i],count);
        }
    }
    printf("%d\n",max);
    return 0;
}
