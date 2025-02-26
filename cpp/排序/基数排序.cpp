//基数排序
//时间复杂度 O(N) 

#include <iostream>
using namespace std;
#define MAXSIZE 1000
 
const int BASE = 10;  //进制
int *arr = new int[MAXSIZE];
int n;
int *help = new int[MAXSIZE];  //辅助数组 
int *cnts = new int[BASE];     //

//返回number在BASE进制下有几位
int bits(int num)
{
	int ans = 0;
	while(num)
	{
		ans++;
		num /= BASE;
	}
	return ans;
 } 
 
 
//基数排序核心代码
//arr内要保证没有负数

void radixSort(int bits)
{
	//offset 为提取数字的哪一位
	//根据最大值在BASE进制下的位数，决定基数排序做多少轮 
	for(int offset = 1; bits > 0; offset *= BASE,bits--)
	{
		//将cnts数组复位
		for(int i = 0; i < BASE; i++)
			cnts[i] = 0; 
		//提取数字的每一位
		for(int i = 0; i < n; i++)
			cnts[(arr[i]/offset)%BASE]++; 
		//cnts 的前缀和 
		//即有多少位 <= 当前位上的数 
		for(int i = 1; i < BASE; i++)
			cnts[i] = cnts[i] + cnts[i-1];
		//根据当前位上的的数进行排序
		//注意必须是从右到左 
		for(int i = n-1; i >= 0; i--)
			help[--cnts[(arr[i]/offset)%BASE]] = arr[i];
		//拷贝到原数组
		for(int i = 0; i < n; i++)
			arr[i] = help[i]; 
	}
} 

//对于 radixSort排序，如果排序的数组中出现负数
//则现将整个数组的每个数减去数组中的最小的那个负数，在进行基数排序 

void sort()
{
	int min = arr[0];  //记录数组中的最小值 
	int max = 0;       //记录数组中的最大值，以便等下求数组的最大位数
	for(int i = 0; i < n; i++)
	{
		if(arr[i] < min)
			min = arr[i];
	} 
	for(int i = 0; i < n; i++)
	{
		//数组中的每个数，减去数组中的最小值，就把arr转成了非负数组
		arr[i] -= min;
		//并求转换后数组的最大值
		if(arr[i] > max)
			max = arr[i]; 
	}
	//数组处理完后，进行基数排序
	radixSort(bits(max));
	//排序完，还原数组
	for(int i = 0; i < n; i++)	
		arr[i] += min; 
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort();
	for(int i = 0; i < n; i++)	
		cout << arr[i] << " ";
	cout << endl;
	system("pause");
	return 0;
 } 
