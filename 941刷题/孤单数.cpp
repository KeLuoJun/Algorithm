#include <stdio.h>
#define N 1000001
int arr[N];
//ц╟ещеепР
void func(int *arr,int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int flag = 0;
        for(int j = 0; j < n-i-1; j++)
        {
            int temp;
            if(arr[j] > arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                flag = 1;
            }
        }
        if(!flag) break;
    }
        
}
int main()
{
    int n;
    scanf("%d",&n);
    n = 2*n+1;
    for(int i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    if(n == 1)
    {
        printf("%d",arr[0]);
        return 0;
    }
    func(arr,n);
    int p1 = 0,p2 = 1;
    while(p2 < n)
    {
        if(arr[p1] == arr[p2])
        {
            p1 = p2 + 1;
            p2 = p1 + 1;
        }
        else
        {
            printf("%d",arr[p1]);
            return 0;
        }
        if(p1 == n-1)
        {
        	printf("%d",arr[p1]);
        	return 0;
		}
    }
}
