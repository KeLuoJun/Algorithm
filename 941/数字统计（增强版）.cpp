#include <stdio.h>
int main()
{
    int m,n;
    scanf("%d %d",&m, &n);
    
    int num;
    int x[10] = {0};
    for(int i = m; i <= n; i++)
    {
        int k = i;
        while(k != 0){
            num = k % 10;
            x[num]++; 
            k /= 10;
        }
    }
    for(int i = 0; i < 10; i++)
    {
        printf("%d ",x[i]);
    }
    return 0;
}
