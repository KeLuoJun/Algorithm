#include <stdio.h>
#include <string.h>
int main()
{
    char a[5][81],t[81];
    for(int i = 0; i < 5; i++)
        scanf("%s",a[i]);
        
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4-i; j++)
        {
            if(strcmp(a[j],a[j+1]) > 0)
            {
                strcpy(t,a[j+1]);
                strcpy(a[j+1],a[j]);
                strcpy(a[j],t);
            }
        }
    printf("After sorted:\n");
    for(int i = 0; i < 5; i++)
        printf("%s\n",a[i]);
    return 0;
}
