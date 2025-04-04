#include <stdio.h>
int fun(int n){
    return n == 1 ? 1 : n + fun(n - 1);
}

int main()
{
    int sum = fun(100);
    printf("sum = %d",sum);
    return 0;
}
