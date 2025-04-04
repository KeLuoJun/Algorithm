#include <stdio.h>
int main()
{
    int n,limit;
    int people[100];
    scanf("%d %d",&n,&limit);
    for(int i = 0; i < n; i++)
        scanf("%d",&people[i]);
    //¶ÔÊý×éÅÅÐò£¨ÉýÐò£©
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
        {
            if(people[j] > people[j+1])
            {
                int t = people[j+1];
                people[j+1] = people[j];
                people[j] = t;
            }
        }

    int l = 0,r = n-1;
    int count = 0;
    while(l < r)
    {
        if(people[l]+people[r] > limit) r--;
        else
        {
            l++;
            r--;
        }
        count++;
    }
    printf("%d",count);
    return 0;
    
}
