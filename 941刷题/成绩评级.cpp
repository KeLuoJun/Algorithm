#include <stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    if(x>=90 && x<=100)
        printf("Great");
    else
        if(x>=70 && x<=89)
            printf("Good");
        else
            if(x>=60 && x<=69)
                printf("Average");
            else
                printf("Poor");
    return 0;
}
