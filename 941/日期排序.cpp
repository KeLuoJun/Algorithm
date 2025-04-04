#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    struct date
    {
        int day;
        int month;
        int year;
        int rank;
    }a[20];
    for(int i = 0; i < n; i++)
        scanf("%d/%d/%d",&a[i].day,&a[i].month,&a[i].year);
    
    date temp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j].year > a[j+1].year)
            {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
            else if(a[j].year==a[j+1].year && a[j].month>a[j+1].month)
            {
                 temp = a[j+1];
                 a[j+1] = a[j];
                 a[j] = temp;
            }
            else if(a[j].year==a[j+1].year&&a[j].month==a[j+1].month&&a[j].day>a[j+1].day)
            {
                temp = a[j+1];
                 a[j+1] = a[j];
                 a[j] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++)
        printf("%02d/%02d/%d\n",a[i].day,a[i].month,a[i].year);
    return 0;
}
