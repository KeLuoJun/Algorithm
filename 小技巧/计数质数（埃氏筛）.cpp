// ��������
// ��������n������С�ڷǸ�����n������������
// �������� : https://leetcode.cn/problems/count-primes/
#include <bits/stdc++.h> 
using namespace std;


// ����ɸͳ��0 ~ n��Χ�ڵ���������
// ʱ�临�Ӷ�O(n * log(logn))
int ehrlich(int n)
{
	// vis[i] = 1������i�Ǻ���
	// vis[i] = 0������i������
	// ��ʼʱ��Ϊ0~n��������������
	int vis[n + 1] = {0};  // 0 ��ʾû���ʹ� 
	for(int i = 2; i * i <= n; i++){
		if(!vis[i]){
			for(int j = i * i; j <= n; j += i){
				vis[j] = 1;
			}
		}
	}
	int cnt = 0;
	for(int i = 2; i <= n; i++){
		if(!vis[i]){
			// ��ʱi���������������ռ���Ҳ���Լ���
			//printf("%d ",i);
			cout << i << " ";
			cnt++;
		}
	}
	cout << endl;
	return cnt;
}


int main()
{
	int n;
	scanf("%d",&n);
	int ans = ehrlich(n);
	printf("%d",ans);
	return 0;
 } 
