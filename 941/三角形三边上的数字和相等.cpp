#include <stdio.h>
int main()
{
	int a,b,c,d,e,f;
	for(a=1;a<=9;a++)
		for(b=1;b<=9;b++)
			for(c=1;c<=9;c++)
				for(d=1;d<=9;d++)
					for(e=1;e<=9;e++)
						for(f=1;f<=9;f++){ 
							if(a!=b && a!=c && a!=d && a!=e && a!=f
							        && b!=c && b!=d && b!=e && b!=f
									        && c!=d && c!=e && c!=f
											   		&& d!=e && d!=f
														    && e!=f)
							{
								if(a+b+c==c+d+e && c+d+e==e+f+a && e+f+a==a+b+c){
									printf("  %d  \n",a);
									printf(" %d %d \n",b,f);
									printf("%d %d %d\n",c,d,e);
									printf("\n"); 
								}
							}
						} 
	return 0;	
 }
