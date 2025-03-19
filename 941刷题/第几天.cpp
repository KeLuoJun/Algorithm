#include <stdio.h>
int main()
{
    int func(int n);
    char data[15];
    int y,m,d,i,j;
    while(scanf("%s",data) != EOF)
    {
        int sum = 0;
        y=0,m=0,d=0;
        for(i = 0; data[i] != '/'; i++)
        {
            y = y*10 + int(data[i] - '0');
        }
        i++;
        for( ; data[i] != '/'; i++)
            m = m*10 + int(data[i] - '0');
        i++;
        for( ; data[i] != '\0'; i++)
            d = d*10 + int(data[i] - '0');
        sum += d;
        for(j = 1; j < m; j++)
        {
            if(j==4 || j==6 || j==9 || j==11)
                sum += 30;
            else if(j==1 || j==3 || j==5 || j==7 || j==8 || j==10 || j==12)
                sum += 31;
            else
            {
                if(j == 2 && func(y))
                    sum += 29;
                else
                    sum += 28;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}

int func(int n)
{
    if(n%4==0 && n%100!=0)
        return 1;
    else
        if(n%400==0)
            return 1;
        else
            return 0;
}
