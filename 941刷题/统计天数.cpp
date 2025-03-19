#include <stdio.h>
#define N 10000000
int num[N];
int main()
{
    int n,count = 1,max = 1;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&num[i]);
        if(i > 0)
        {
            if(num[i] > num[i - 1]){
                count ++;
                if(count > max)
                    max = count;}
            else
                count = 1;
        }
    }
    printf("%d",max);
    return 0;
}
