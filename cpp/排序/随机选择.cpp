//求数组中第k小或n-k大的数 

#include <iostream>
#include <time.h>
#include<stdlib.h>
using namespace std;
#define MAXSIZE 1000

int arr[MAXSIZE];
int first;
int last;

void swap(int l,int r)
{
	int temp = arr[l];
	arr[l] = arr[r];
	arr[r] = temp;
}

void partition(int l,int r,int x)
{
	first = l;
	last = r;
	int i = l;
	while(i <= last)
	{
		if(arr[i] == x)
			i++;
		else if(arr[i] < x)
			swap(first++,i++);
		else if(arr[i] > x)
			swap(last--,i);
	}
}

int randomizedSelect(int i)
{
	int ans;
	srand((unsigned)time(0));
	for(int l = 0,r = sizeof(arr)/sizeof(arr[0])-1; l <= r;)
	{
		partition(l,r,arr[l+(int)rand()%(r-l+1)]);
		if(i < first)
			r = first-1;
		else if(i > last)
			l = last+1;
		else
		{
			ans = arr[i];
			break;
		}
	}
	return ans;
} 

int test()
{
	int n,k;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> k;
	int ans = randomizedSelect(k-1);
	cout << ans << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}
