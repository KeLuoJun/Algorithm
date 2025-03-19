#include <stdio.h>
int main()
{
    int start,end;
    scanf("%d %d",&start,&end);
    int h,m,h1,h2,m1,m2;
    h1 = start / 100;
    h2 = end / 100;
    m1 = start % 100;
    m2 = end % 100;
    h = h2 - h1;
    if(m2 < m1)
    {
        m = (60 - m1) + m2;
        h -= 1;
        printf("%02d:%02d",h,m);
    }
    else
    {
        m = m2 - m1;
        printf("%02d:%02d",h,m);
    }
    return 0;
}
