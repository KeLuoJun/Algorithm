#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int count = 0;
    //检查与7无关的数
    for(int i = 1; i <= n; i++){
        //检查某位数上是否有7
        int j = i;
        while(j){
            int k = j % 10;
            if(k == 7){
                break;
            }
			j /= 10;
        }
		if(j == 0 && i % 7 != 0){
			count += i * i;
		}
    }
    printf("%d",count); 
    return 0;
}
