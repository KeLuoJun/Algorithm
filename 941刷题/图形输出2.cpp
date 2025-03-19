#include <stdio.h>
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    int k = 1, a = n;
    for(int i = 1; i <= n; i ++){     //控制行数 
        for(int k = 1; k <= a - 1; k ++){    //控制每一行前面的空格 
        	printf(" ");
		}
        for(int j = 1; j <= m; j ++){    //控制每一行的列数 
            printf("* ");
        }
        a --;
        printf("\n");
    }
    return 0;
}
