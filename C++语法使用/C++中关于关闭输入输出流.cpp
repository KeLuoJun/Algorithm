#include <iostream>
using namespace std; 

int main()
{
	//关闭C++和C的输入输出流的同步，提高C++的输入输出效率
	std::ios::sync_with_stdio(false);
	//解除cin和cout的绑定，让它们可以独立缓冲
	std::cin.tie(0);
	int n;
	cin >> n;
	cout << n << endl;
	return 0;
}

