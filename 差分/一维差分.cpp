//差分操作必须在数组值都为 0 的数组上进行操作
//再将差分数组分别加上原数组上的值 

#include <iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int *arr = new int[n+2];
	int *help = new int[n+2]();
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int m;
	cin >> m;   //有多少次修改的操作 
	int l,r,num;  //修改操作  修改范围：a-b 之间的每个数+c 
	//修改差分数组 
	for(int i = 0; i < m; i++)
	{
		cin >> l >> r >> num;
		//相当于 l--,r--; 
		help[l-1] += num;  
		help[r] -= num;
	}
	for(int i = 1; i < n; i++)
	{
		help[i] += help[i-1];   //前缀和 
	}
	//还原初始数组 
	for(int i = 0; i < n; i++)
	{
		arr[i] += help[i];
		cout << arr[i] << " ";
	}
	return 0;
		
		
} 
