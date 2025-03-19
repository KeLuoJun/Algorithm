#include <stdio.h>
#define MAX 1000001
int num[MAX];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&num[i]);
        num[i] += num[i-1];   //前缀和 
    }
    int ans = 0;
    int l = 1,r = 2;
    while(l < n && r <= n)
    {
        if(l == r) r++;
        while(num[r]-num[l] < m && r <= n) //r<=n 创造外循环结束条件 
        {
            r++;
        }
        while(num[r]-num[l] > m && l < n)
        {
            l++;
        }
        if(num[r]-num[l] == m)
        {
        	ans++;
        	l++;
		}
    }
    printf("%d\n",ans);
    return 0;
}
