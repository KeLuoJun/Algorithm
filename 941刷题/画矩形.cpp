#include <stdio.h>
int main()
{
    int x,y,z;
    char c;
    scanf("%d %d %c %d", &x, &y, & c, &z);
    
    if(z == 1){
    //¿ØÖÆÐÐÊý
        for(int i = 1; i <= x; i++){
            for(int j = 1; j <= y; j++)
                printf("%c",c);
            printf("\n");
        }
    }
    
    if(z == 0){
        for(int i = 1; i <= x; i++){
            if(i == 1 || i == x){
                for(int j = 1; j <= y; j++){
                    printf("%c",c);
                }
                printf("\n");
            }
            else{
                printf("%c",c);
                for(int j = 1; j <= y - 2; j++){
                    printf(" ");
                }
                printf("%c",c);
                printf("\n");
            }
        }
    }
    return 0;
}
