#include <stdio.h>
int akm(int m,int n)
{
    if(m == 0)
        return n+1;
    else if(m > 0 && n == 0)
        return akm(m-1,1);
    else
        return akm(m-1,akm(m,n-1));

}
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int num = akm(m,n);
    printf("%d\n",num);
    return 0;
}
