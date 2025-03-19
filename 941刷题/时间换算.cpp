#include <stdio.h>
int main()
{
    int h,m,s;
    scanf("%d:%d:%d",&h,&m,&s);
    int n;
    scanf("%d",&n);
    s = s + n;
    if(s < 60)
        printf("%02d:%02d:%02d",h,m,s);
    else
    {
        s -= 60;
        m += 1;
        if(m < 60)
            printf("%02d:%02d:%02d",h,m,s);
        else
        {
        	m -= 60; 
            h += 1;
            if(h <= 23)
                printf("%02d:%02d:%02d",h,m,s);
            else
            {
                h -= 23;
                printf("%02d:%02d:%02d",h,m,s);
            }
        }
        
    }
    return 0;
}
