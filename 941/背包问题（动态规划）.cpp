#include <bits/stdc++.h>//C++���ܿ�
//��̬�滮
void Knapsack(int v[], int w[], int c, int n, int m[][100]);
//�������
void Traceback(int m[][100], int w[], int c, int n, int x[]);
int GetMin(int a,int b);//��Сֵ
int GetMax(int a,int b);//���ֵ
 
 
int main(){
    int c, n;
    printf("����������");
    scanf("%d",&c);
 
    printf("��Я����Ʒ������");
    scanf("%d",&n);
 
 
    int* w =(int *)malloc(sizeof(int)*(n+5));
    int* v =(int *)malloc(sizeof(int)*(n+5));
 
    printf("����Ʒ������");
    for (int i = 1; i <= n; i++){
        scanf("%d",w+i);
    }
 
    printf("����Ʒ��ֵ��");
    for (int i = 1; i <= n; i++){
        scanf("%d",v+i);
    }
 
    int m[100][100] = { 0 };//��ά�����ʼ��
    int x[100] = { 0 };//��ʾ�ĸ�Я���ĸ���Я������(0,1,0,0��1.......)
 
    //����
    Knapsack(v, w, c, n, m);//�õ���ά���� 
 
   printf("��ά���飺\n");
    for (int i = n; i >=1; i--){
        for (int j = 0; j <= c; j++){
            printf(" %d ",m[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
 
    //���ݵõ���
    Traceback(m, w, c, n, x);//�õ��ĸ�Я���ĸ���Я��������x[n]��
    putchar('\n');
    printf("�ﵽ����ֵ�����Ž�Ϊ��");
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
 
//��ʽ�����ֱ�Ϊ��ֵ/��Ʒ����/��������/��Ʒ����/��ά����(�洢m(i,j)��Ӧֵ)
void Knapsack(int v[], int w[], int c, int n, int m[][100]){
   //ֻ�ŵ�n����Ʒ����ά����ĵ�һ��
    int the_max_of_j  = GetMin(w[n] - 1, c);
    for (int j = 0; j <= the_max_of_j ; j++){
        m[n][j] = 0;//��n����Ʒ�Ų���
    }
 
    for (int j = w[n]; j <= c; j++){
        m[n][j] = v[n];//�ܷ��µ�n����Ʒ
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
 
