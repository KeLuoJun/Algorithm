#include <stdio.h>
#include <string.h>
int main()
{
    int m,n,a = 0,b = 0;
    char ch[1002];
    scanf("%d",&m);
    gets(ch);
    int len = strlen(ch) - 1;
    int sign = 0,flag = 0;
    for(int j = 1; j <= len; j++)
    {
        if(ch[j] != '0')
            sign++;
    }
    for(int i = 1; i <= len; i++)
    {
        if(ch[i] != '0')
        {
            flag++;
            int x = ch[i] - '0';
            if(flag != sign)
                printf("%d*%d^%d+",x,m,len-i);
            else
                printf("%d*%d^%d",x,m,len-i);            
        }
    }
    
    return 0;
}
