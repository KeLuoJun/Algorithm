#include <stdio.h>
int main()
{
	int k,a,b,i,count1,count2;
	for(k=4;k<=100;k=k+2){
		for(a=2;a<=k/2;a++){
			//判断a是否为质数
			count1=0;
			for(i=2;i<=a-1;i++){
				if(a%i==0){
					count1++;
					break;
				}
			} 
			if(count1==0){   //如果a是质数 
				b=k-a;
				//判断b是否为质数
				count2=0;
				for(i=2;i<=b-1;i++){
					if(b%i==0){
						count2++;
						break;
					}
				}
				if(count2==0){   //如果b是质数 
					printf("%d=%d+%d\n",k,a,b);
					
				}
			}
		}
		continue;
	}
	return 0; 
 } 
