#include <stdio.h>
int checkCard(char cardNum[])
{
    int sum = 0,sum1 = 0,sum2 = 0,num;
    for(int i = 15; i >= 1; i-=2)
    {
        sum1 += int(cardNum[i] - '0');
    }
    for(int i = 14; i >= 0; i-=2)
    {
            num = int(cardNum[i] - '0') * 2;
            if(num > 9)
                num -= 9;
            sum2 += num;
    }
    sum += sum1 + sum2;
    if(sum % 10 == 0)
        return 1;
    else
        return 0;
}

int main()
{
    char cardNum[17];
    while(scanf("%s",cardNum) != EOF)
    {
        if(checkCard(cardNum))
            printf("Pass\n");
        else
            printf("Fail\n");
    }
    return 0;
    
}
