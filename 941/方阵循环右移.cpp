#include<stdio.h>  
int main(){  
    int a[10][10],i,j,n,m;  
    scanf("%d %d",&m,&n);  
    for(i=0;i<n;i++)  
        for(j=0;j<n;j++)  
            scanf("%d",&a[i][j]);  
    m=m%n;  //可能会出现m比n大，取余
    for(i=0;i<n;i++){  
        for(j=n-m;j<n;j++)   //先输出 右移的部分，差值 n- m
            printf("%d ",a[i][j]);  
        for(j=0;j<n-m;j++)   //输出剩下的部分   
            printf("%d ",a[i][j]);  
        printf("\n");  
    }         
    return 0;   
}

