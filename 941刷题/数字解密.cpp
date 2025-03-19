/*
小明经常解密数字串，但是有一天他碰到了难题，
有一串被加密的数字，它的解密规则是将第一个数字删除，
将第二个数字放到数字串的末尾，形成一个新的数字串，重复上述操作，
一直到最后一个数字被删除，
然后按删除的顺序把这些数字重新排列
（第一个被删除的数排第一个，第二个被删除的数排第二个，以此类推），
得到的数字串就是原来的数字串的顺序。
*/
#include <stdio.h>
#define N 101
int main()
{
    int n,t;
    scanf("%d",&n);
    int num[N],fresh[N];
    for(int i = 1; i <= n; i++)
        scanf("%d",&num[i]);
        
    for(int i = 1; i <= n; i++)
    {
        fresh[i] = num[i];
        if(i == n)
            break;
        t = num[i+1];
        for(int j = i+1; j <= n; j++)
            num[j] = num[j+1];
        num[n] = t;
    }
    for(int i = 1; i <= n; i++)
        printf("%d",fresh[i]);
    return 0;
}
