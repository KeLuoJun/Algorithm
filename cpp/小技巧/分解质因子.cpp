#include <iostream>
using namespace std;

// ��ӡ����n�������ӣ�ʱ�临�Ӷ�O(����n)
void f(int n)
{
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			cout << i << " ";
			while(n % i == 0){
				n /= i;
			}
		}
	}
	// ե�ɵ���������Լ���������ե����ȥ�� 
	if(n > 1)
		cout << n << endl;
}

int main()
{
	int n = 243242123;
	f(n);
	return 0;
 } 
