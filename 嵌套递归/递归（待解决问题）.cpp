#include <iostream>
using namespace std;
int n,kind = 0;
int m1[10000][10],m2[10];

//�������ӣ�https://www.luogu.com.cn/problem/P2089 


////��һ�� 
//void fuc(int total,int a)
//{
//    if(total == n && a == 10)
//    {
//        for(int j = 0; j < 10; j++)
//            m1[kind][j] = m2[j];
//        kind++;
//        
//    }
//    else if(total >= n) return;
//    else
//    {
//    	for(int i = 1; i <= 3; i++)
//	    {
//	        m2[a] = i;
//	        fuc(total+i,a+1); 
//	    }
//	}
//}

//Ϊʲô��һ�ֲ��Զ��ڶ�������ȷ�� 
//�ڶ��� 
void fuc(int total,int a)
{
	if(a == 10)
	{
		if(total == n)
		{
			for(int j = 0; j < 10; j++)
	            m1[kind][j] = m2[j];
	        kind++;
		}
	}
	else if(total >= n);
	else
	{
		for(int i = 1; i <= 3; i++)
	    {
	        m2[a] = i;
	        fuc(total+i,a+1); 
	    }
	}
} 



int main()
{
    cin >> n;
    fuc(0,0);
    cout << kind << endl;
    for(int i = 0; i < kind; i++)
    {
        for(int j = 0; j < 10; j++)
            cout << m1[i][j] << " ";
        cout << endl;
    }
    return 0;
        
}
