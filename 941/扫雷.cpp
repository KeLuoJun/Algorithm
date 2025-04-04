#include <stdio.h>
int main()
{
    int n,m,count;
    int b[100][100] = {0};
    char ch[100][100] = {0};
    scanf("%d %d",&n,&m);
    
    for(int i = 0; i < n; i++){
    	scanf("%s",ch[i]);
	}
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            count = 0;
            if(ch[i][j] == '*')
                b[i][j] = -1;
            else
            {
                if(ch[i-1][j-1] == '*')
                    count ++;
                if(ch[i-1][j] == '*')
                    count++;
                if(ch[i-1][j+1] == '*')
                    count++;
                if(ch[i][j+1] == '*')
                    count ++;
                if(ch[i+1][j+1] == '*')
                    count ++;
                if(ch[i+1][j] == '*')
                    count ++;
                if(ch[i+1][j-1] == '*')
                    count ++;
                if(ch[i][j-1] == '*')
                    count ++;
                    
                b[i][j] = count;
            }
        }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
        {
        	if(b[i][j] < 0)
        		printf("*");
        	else
        		printf("%d",b[i][j]);
		}  
        printf("\n");
    }
    return 0;
}
