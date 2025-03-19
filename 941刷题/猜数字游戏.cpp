#include <stdio.h>
int main()
{
    int n,count = 0,num,N;
    scanf("%d%d",&n,&N);
    while(1)
    {
        scanf("%d",&num);
        count++;
        if(count > N || num < 0){
            printf("Game Over\n");
            break;
        }
        else if(num == n)
        {
            if(count == 1) printf("Bingo!\n");
            else if(count <= 3) printf("Lucky You!\n");
            else if(count <= N) printf("Good Guess!\n");
            break;
        }
        else
        {
            if(num > n) printf("Too big\n");
            if(num < n) printf("Too small\n");
        }
    }
    return 0;
}
