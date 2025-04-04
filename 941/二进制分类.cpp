#include <stdio.h>
char binaryType(int n)
{
    int count0 = 0,count1 = 0;
    int num;
    while (n != 0)
    {
        num = n % 2;
        n /= 2;
        if(num == 1)
            count1++;
        if(num == 0)
            count0++;
    }
    if(count0 >= count1)
        return 'B';
    else 
        return 'A';
    
}
int main()
{
    int n;
    scanf("%d",&n);
    int counta = 0,countb = 0;
    for(int i = 1; i <= n; i++)
    {
        if(binaryType(i) == 'A')
            counta++;
        if(binaryType(i) == 'B')
            countb++;
    }
    printf("%d %d",counta,countb);
    return 0;
}
