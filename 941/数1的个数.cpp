#include <stdio.h>
int countone(int n){
    int count = 0;
    for(int i = 1; i <= n; i++){
        int j = i;
        while(j){
            if(j % 10 == 1){
                count ++;
            }
            j /= 10;
        }
    }
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d",countone(n));
    return 0;
}
