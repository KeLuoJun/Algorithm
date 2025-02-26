// ɾ��1�����ֺ󳤶�Ϊk������������ۼӺ�
// ����һ������nums�������ɾ��һ�����ֺ����������
// ����Ϊk������������ۼӺͣ�ɾ���ĸ���������
// ��������֤
// ���е�С���⣩ 

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
const int N = 1e5;
int n, k;
int arr[N];

void Delete(int *num, int index)
{
	int i = 0;
	for(int j = 0; j < n; j++){
		if(j != index){
			num[i++] = arr[j];
		}
	}
}

int lenKmaxSum(int *num)
{
	int ans = INT_MIN;
	int sum = 0;
	for(int i = 0; i < n - 1; i++){
		sum += num[i];
		if(i >= k - 1){
			ans = max(ans, sum);
			sum -= num[i - k + 1];
		}
	}
	return ans;
}

// ��������
// Ϊ�˲���
// ö��ÿһ���������ҵ�����ۼӺ�
int maxSum1()
{
	if(n <= k) return 0;
	int ans = INT_MIN;
	for(int i = 0; i < n; i++){
		int *num = new int[n];
		Delete(num, i);
		ans = max(ans, lenKmaxSum(num));
		delete[] num;
	} 
	return ans;
}





// ��ʽ����
// ʱ�临�Ӷ�O(N)
// �������Ϊ k+1 ����������ۼӺͣ��ټ�ȥ���е���Сֵ���õ������У� 
int maxSum2()
{
	if(n <= k) return 0;
	// �������� : ά�ִ�������Сֵ�ĸ��½ṹ������054������
	int *window = new int[n + 1];
	int l = 0, r = 0;
	// �����ۼӺ�
	int sum = 0;
	int ans = INT_MIN;
	for(int i = 0; i < n; i++){
		// �������� 
		// Сѹ�� 
		while(l < r && arr[window[r - 1]] >= arr[i]){
			r--;
		}
		window[r++] = i;   // �洢�����±� 
		sum += arr[i];
		if(i >= k){
			ans = max(ans, sum - arr[window[l]]);
			if(window[l] == i - k){
				// �������� : �����������������λ�ù����ˣ��Ӷ����е���
				l++;
			}
			sum -= arr[i - k];
		}
	}
	delete[] window;
	return ans;
}

// ������ 
int main()
{
	int testTime = 10000;
	srand((unsigned)time(NULL));
	cout << "���Կ�ʼ" << endl;
	for(int i = 0; i < testTime; i++){
		n = rand() % 15;
		k = rand() % n;
		for(int j = 0; j < n; j++){
			arr[j] = rand() % 100;
		}
		int ans1 = maxSum1();
		int ans2 = maxSum2();
		cout << ans1 << " " << ans2 << endl;
		if(ans1 != ans2){
			cout << "������" << endl; 
		}
	}
	cout << "���Խ���" << endl;
	return 0;
}
 
