#include <stdio.h>
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    int k = 1, a = n;
    for(int i = 1; i <= n; i ++){     //�������� 
        for(int k = 1; k <= a - 1; k ++){    //����ÿһ��ǰ��Ŀո� 
        	printf(" ");
		}
        for(int j = 1; j <= m; j ++){    //����ÿһ�е����� 
            printf("* ");
        }
        a --;
        printf("\n");
    }
    return 0;
}
