#include <stdio.h>

int Decompose(int *a,int num)
{
    int i = 0;
    while(num)
    {
        a[i++] = num % 10;
        num /= 10;
    }
    return i;
}

int func(int *a, int num, int n)
{
    printf("%d->",num);
    int num_new = 0;
    for(int i = n-1; i >= 0; i--)
    {
        num_new += a[i] * a[i];
        if(i)
            printf("%d*%d+",a[i],a[i]);
        else
            printf("%d*%d",a[i],a[i]);
    }
    printf("=%d\n",num_new);
    return num_new;
}


int main()
{
    int num;
    int a[6];
    scanf("%d",&num);
    if(num == 1 || num == 145)
	{
		printf("%d\n",num);
		return 0;
	} 
    while(num != 145)
    {
        int n = Decompose(a,num);
        num = func(a,num,n);
    }
    return 0;
}
