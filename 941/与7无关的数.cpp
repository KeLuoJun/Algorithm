#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int count = 0;
    //�����7�޹ص���
    for(int i = 1; i <= n; i++){
        //���ĳλ�����Ƿ���7
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
