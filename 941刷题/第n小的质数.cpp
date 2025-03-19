#include <stdio.h>
int pr(int n)
{
    int count = 0;
    for(int i = 2; i < n; i++)
    {
        if(n % i == 0){
            count = 1;
            break;
        }
    }
    if(count == 0)
        return 1;
    else
        return 0;
}

int main()
{
    int n;
    scanf("%d",&n);
    int i = 2,num = 0;
    while(1)
    {
        if(pr(i))
            num ++;
        if(num == n)
            break;
        i++;
    }
    printf("%d",i);
    return 0;
}
