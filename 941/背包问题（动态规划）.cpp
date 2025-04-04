#include <bits/stdc++.h>//C++万能库
//动态规划
void Knapsack(int v[], int w[], int c, int n, int m[][100]);
//回溯求解
void Traceback(int m[][100], int w[], int c, int n, int x[]);
int GetMin(int a,int b);//最小值
int GetMax(int a,int b);//最大值
 
 
int main(){
    int c, n;
    printf("背包容量：");
    scanf("%d",&c);
 
    printf("可携带物品数量：");
    scanf("%d",&n);
 
 
    int* w =(int *)malloc(sizeof(int)*(n+5));
    int* v =(int *)malloc(sizeof(int)*(n+5));
 
    printf("各物品重量：");
    for (int i = 1; i <= n; i++){
        scanf("%d",w+i);
    }
 
    printf("各物品价值：");
    for (int i = 1; i <= n; i++){
        scanf("%d",v+i);
    }
 
    int m[100][100] = { 0 };//二维数组初始化
    int x[100] = { 0 };//表示哪个携带哪个不携带比如(0,1,0,0，1.......)
 
    //背包
    Knapsack(v, w, c, n, m);//得到二维数组 
 
   printf("二维数组：\n");
    for (int i = n; i >=1; i--){
        for (int j = 0; j <= c; j++){
            printf(" %d ",m[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
 
    //回溯得到解
    Traceback(m, w, c, n, x);//得到哪个携带哪个不携带，放在x[n]中
    putchar('\n');
    printf("达到最大价值的最优解为：");
    for (int i = 1; i <= n; i++){
        if(i==1){
        printf("%d",x[i]);
        } else{
            printf(" %d",x[i]);
        }
    }
}
 
void Traceback(int m[][100], int w[], int c, int n, int x[]){
    for (int i = 1; i <= n; i++){
        if (m[i][c] == m[i + 1][c]){
            x[i] = 0;
        } else{
            x[i] = 1;
            c -= w[i];
        }
    }
}
 
//形式参数分别为价值/物品重量/背包容量/物品个数/二维数组(存储m(i,j)相应值)
void Knapsack(int v[], int w[], int c, int n, int m[][100]){
   //只放第n个物品即二维数组的第一行
    int the_max_of_j  = GetMin(w[n] - 1, c);
    for (int j = 0; j <= the_max_of_j ; j++){
        m[n][j] = 0;//第n个物品放不下
    }
 
    for (int j = w[n]; j <= c; j++){
        m[n][j] = v[n];//能放下第n个物品
    }
//-------------------------------------------------------------
    for (int i = n - 1; i >= 1; i--){
        the_max_of_j  = GetMin(w[i] - 1, c);
        for (int j = 0; j <= the_max_of_j ; j++){
            m[i][j] = m[i + 1][j];
        }
        for (int j = w[i]; j <= c; j++){
            m[i][j] = GetMax(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);
        }
    }
}
int GetMin(int a,int b){
    if(a >= b) return b;
        return a;
}
int GetMax(int a,int b){
    if( a>=b ) return a;
        return b;
}
 
