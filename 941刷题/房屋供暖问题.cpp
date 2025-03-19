#include <stdio.h>
#include <math.h>
int main()
{
    void sort(int *arr,int n);
    int max(int a,int b);
    int n,m;
    scanf("%d %d",&n,&m);
    int house[100],heat[100];
    for(int i = 0; i < n; i++)
        scanf("%d",&house[i]);
    for(int i = 0; i < m; i++)
        scanf("%d",&heat[i]);
    sort(house,n);
    sort(heat,m);
    int p1 = 0,p2 = 0;  //p1指向房屋，p2指向供暖器 
    int ans = 0;
    while(p1 < n)
    {
        if(p2 == m-1)   //当p2指到最后一个后，一直都是最优解 
        {
            ans = max(ans,abs(house[p1++]-heat[p2]));
        }
        else
        {
        	//每一个房屋都得到最优解，然后取最优解的最大值 
            if(abs(house[p1]-heat[p2]) < abs(house[p1]-heat[p2+1]))
            {    
                ans = max(ans,abs(house[p1++]-heat[p2]));
            }
            else
            {   //相等时也要移动p2 
                ans = max(ans,abs(house[p1]-heat[++p2]));
            }
            
        }
    }
    printf("%d",ans);
    return 0;
    
}
void sort(int *arr,int n)
{
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
        {
            int t = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = t;
        }
}
int max(int a,int b)
{
    return a > b ? a : b;
}
