////方案一 
//#include <iostream>
//#include <algorithm>
//#include <set>
//using namespace std;
//
//int main()
//{
//	int n,m,num;
//	scanf("%d%d",&n,&m);
//	int a = 0,b = 0;
//	multiset<int>odd;
//	multiset<int>even;
//	for(int i = 0; i < n; i++)
//	{
//		scanf("%d",&num);
//		if(num % 2) odd.insert(num);
//		else even.insert(num);
//	}
//
//	bool flag = true; //先手 
//	while(m--)
//	{
//		if(flag)
//		{
//			
//			int num = *(--even.end())++;
//			odd.insert(num);
//			even.erase(--even.end());
//			flag = false;
//		}
//		else
//		{
//			int num = *(--odd.end())--;
//			even.insert(num);
//			odd.erase(--odd.end());
//			flag = true;
//		}
//	}
//	int ans = 0;
//	for(multiset<int>::iterator it = odd.begin(); it != odd.end(); it++)
//		ans += *it;
//	printf("%d\n",ans+1);
//	return 0;
//} 

//方案二 
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 1;
int *odd = new int[MAXN];
int *even = new int[MAXN];

int main()
{
	int n,m,num;
	scanf("%d%d",&n,&m);
	int a = 0,b = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&num);
		if(num % 2) odd[a++] = num;
		else even[b++] = num;
	}
	sort(odd, odd + a);
	sort(even, even + b);
	bool flag = true; //先手 
	while(m--)
	{
		if(flag)
		{
			even[b - 1]++;
			odd[a++] = even[b - 1];
			b--;
			sort(odd, odd + a);
			flag = false;
		}
		else
		{
			odd[a - 1]--;
			even[b++] = odd[a - 1];
			a--;
			sort(even, even + b);
			flag = true;
		}
	}
	int ans = 0;
	for(int i = 0; i < a; i++)
		ans += odd[i];
	printf("%d\n",ans);
	return 0;
} 

