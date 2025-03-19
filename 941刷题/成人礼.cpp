#include<stdio.h>
int y(int n)
{
    if (n % 4 == 0 && n % 100 != 0)
    	return 1;
	else if (n % 400 == 0)
	    return 1;
	else
	    return 0;
}

int main()
{
    int year, month, day;
    scanf("%d %d %d",&year,&month,&day);
    year += 18;
    if(month == 2 && day == 29)
    {
        if(y(year))
            printf("%d %d %d",year,month,day);
        else
            printf("-1");
    }
    else
        printf("%d %d %d",year,month,day);
	
	return 0;
}

