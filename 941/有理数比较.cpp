#include <stdio.h>
int main()
{
    char s[8];
    int a1,a2,b1,b2;
    double num1,num2;
    gets(s);
    a1 = int(s[0] - '0');
    a2 = int(s[4] - '0');
    b1 = int(s[2] - '0');
    b2 = int(s[6] - '0');
    num1 = (double)a1 / b1;
    num2 = (double)a2 / b2;
    if(num1 > num2)
        printf("%d/%d > %d/%d",a1,b1,a2,b2);
    else if(num2 == num1)
        printf("%d/%d = %d/%d",a1,b1,a2,b2);
    else if(num1 < num2)
        printf("%d/%d < %d/%d",a1,b1,a2,b2);
    return 0;
}
