#include <stdio.h>
int main()
{
    char poem[4][30];
    for(int i = 0; i < 4; i++)
        scanf("%s",poem[i]);
        
    char head[15];
    int k = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 3; j++)
        	head[k++] = poem[i][j];
            //错误 （一个中文字符占3个字节） head[i] = poem[i][j];
            
    head[k] = '\0';
    printf("%s\n",head);
    return 0;
}
