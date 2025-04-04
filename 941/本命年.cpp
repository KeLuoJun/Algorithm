#include <stdio.h>
#define N 1000
int main()
{
    int t,year_basis = 2020;
    scanf("%d",&t);
    int year[N];
    for(int i = 0; i < t; i++)
        scanf("%d",&year[i]);
        
    for(int i = 0; i < t; i++)
    {
        int x = year[i] - year_basis;
        if(x > 11)
            while(x > 11)
                x -= 12;
        if(x < -11){
            while(x < -11)
                x += 12;
            x = 11 - (-x);
        }
        if(x < 0 && x >= -11)
            x = 11 - (-x);
            
        switch (x)
        {
            case 0:
                printf("Rat\n");
                break;
            case 1:
                printf("Ox\n");
                break;
            case 2:
                printf("Tiger\n");
                break;
            case 3:
                printf("Rabbit\n");
                break;
            case 4:
                printf("Dragon\n");
                break;
            case 5:
                printf("Snake\n");
                break;
            case 6:
                printf("Horse\n");
                break;
            case 7:
                printf("Sheep\n");
                break;
            case 8:
                printf("Monkey\n");
                break;
            case 9:
                printf("Rooster\n");
                break;
            case 10:
                printf("Dog\n");
                break;
            case 11:
                printf("Pig\n");
                break;
        }
    }
    return 0;
}
