#include <stdio.h>
#include <stdlib.h>
int cmp(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}
int min(int a,int b)
{
    if(a < b) return a;
    else return b;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[100000],b[100000];
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    for(int i = 0; i < n; i++)
        scanf("%d",&b[i]);
        
    qsort(a,n,sizeof(a[0]),cmp);
    qsort(b,n,sizeof(b[0]),cmp);
    int ans = 1e9;
    int i = 0, j = 0;
    while(i < n || j < n)
    {
        if(a[i] == b[j])
        {
            ans = 0;
            break;
        }
        int now = abs(a[i] - b[j]);
        ans = min(ans,now);
        if(a[i] < b[j] && i+1 < n) 
            i++;
        else if(b[j] < a[i] && j+1 < n)
            j++;
        else if(a[i] < b[j] && i == n-1)
            break;
        else if(b[j] < a[i] && j == n-1)
            break;
    }
    printf("%d\n",ans);
    return 0;
}
