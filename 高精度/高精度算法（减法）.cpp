#include <stdio.h>
#include <string.h>
int main()
{
    char a[100],b[100];
    scanf("%s",a);
    scanf("%s",b);
    int x[100] = {0},y[100] = {0};
    int lenx = strlen(a);
    int leny = strlen(b);
    int flag = 0;
    if(lenx < leny || (leny == lenx && strcmp(a,b) < 0))
    {
        flag = 1;
        for(int i = 0; i < leny; i++)
            x[i] = b[leny-i-1] - '0';
        for(int i = 0; i < lenx; i++)
            y[i] = a[lenx-i-1] - '0';
    }
    else
    {
        for(int i = 0; i < lenx; i++)
            x[i] = a[lenx-i-1] - '0';
        for(int i = 0; i < leny; i++)
            y[i] = b[leny-i-1] - '0';
    }
        
    int len = lenx;
    if(leny > len) len = leny;
    for(int i = 0; i < len; i++)
    {
        x[i] = x[i]-y[i];
        if(x[i] < 0)
        {
            x[i+1] -= 1;
            x[i] += 10;
        }
    }
    if(x[len-1] == 0) len--;
    if(flag == 1)
        printf("-");
    for(int i = 0; i < len; i++)
        printf("%d",x[len-i-1]);
    return 0;
}
