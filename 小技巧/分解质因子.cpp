#include <iostream>
using namespace std;

// 打印所有n的质因子，时间复杂度O(根号n)
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
	// 榨干到最后发现是自己，不能再榨干下去了 
	if(n > 1)
		cout << n << endl;
}

int main()
{
	int n = 243242123;
	f(n);
	return 0;
 } 
