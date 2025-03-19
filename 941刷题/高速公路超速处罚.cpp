#include <stdio.h>
int main()
{
    int speed,limit;
    double x;
    while(scanf("%d %d",&speed,&limit) != EOF)
    {
		int x1 = limit * 1.1,x2 = limit * 1.5;
        if(speed < x1)
            printf("OK\n");
        
             
        if(speed >= x2)
        {
            x = (double)(speed - limit) / limit * 100;
            printf("Exceed %.0lf%%. License Revoked\n",x);
        }
        else
        {
        	if(speed >= x1)
	        {
	            x = (double)(speed - limit) / limit * 100;
	            x = (int)x;
	            printf("Exceed %.0lf%%. Ticket 200\n",x);
	        }
		}
    }
    return 0;
}
