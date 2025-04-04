#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    struct data
    {
        char name[10];
        int birth;
        char num[17];
    }a[10],temp;
    for(int i = 0; i < n; i++)
    {
        scanf("%s %d %s",a[i].name,&a[i].birth,a[i].num);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j].birth > a[j+1].birth)
            {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++)
        printf("%s %d %s\n",a[i].name,a[i].birth,a[i].num);
        return 0;
}
