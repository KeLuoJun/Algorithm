#include <iostream>
using namespace std;

/*
���룺5
1 4 2 5 3

����������������������ǵĺ�Ϊ��
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1 4 2] = 7
[4 2 5] = 11
[2 5 3] = 10
[1 4 2 5 3] = 15
���ǽ�����ֵ��͵õ� 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
 

*/


int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int sum = 0;
    int step = 0;
    while(step <= n)
    {
        for(int i = 0; i < n; i++)
        {
            if(i+step < n)
            {
                int num = i+step;
                while(num >= i)
                {
                	sum += arr[num];
                	num--;
				}
                    
            }
            else
                break;
        }
        step += 2;
    }
    cout << sum << endl;
    delete arr; 
    return 0;
}
