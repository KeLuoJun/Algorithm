// ���Է�ת1�ε����������������ۼӺ�
// ����һ������nums��
// ��������������ѡ����������һ�ν��з�ת��Ҳ��������������ĵ���
// ���緭ת[1,2,3,4,5,6]��[2~4]��Χ���õ�����[1,2,5,4,3,6]
// ���ر������ⷭת1��֮�������������ۼӺ�
// ��������֤

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
const int N = 1e5;
int n;
int arr[N];

// nums[l...r]��Χ�ϵ����ֽ����������
void reverse(int l, int r)
{
	while(l < r){
		int tmp = arr[l];
		arr[l++] = arr[r];
		arr[r--] = tmp;
	}
}
// ��������������ۼӺ�
int maxSum()
{
	int ans = arr[0];
	for(int i = 1, pre = arr[0]; i < n; i++){
		pre = max(arr[i], pre + arr[i]);
		ans = max(ans, pre);
	}
	return ans;
}

// ��������
// Ϊ����֤
int maxSumReverse1()
{
	int ans = INT_MIN;
	for(int l = 0; l < n; l++){
		for(int r = l; r < n; r++){
			reverse(l, r);
			ans = max(ans, maxSum());
			reverse(l, r);
		} 
	}
	return ans;
}


// ��ʽ����
// ʱ�临�Ӷ�O(n)
int maxSumReverse2()
{
	// start[i] : ���б�����i��ͷ���������У�����ۼӺ��Ƕ���
	int *start = new int[n];
	start[n - 1] = arr[n - 1];
	for(int i = n - 2; i >= 0; i--){
		// nums[i]
		// nums[i] + start[i+1]
		start[i] = max(arr[i], arr[i] + start[i + 1]);
	}
	
	int ans = start[0];
	// end : �����������i-1��β�����е�����ۼӺ�
	int end = arr[0]; // �� start �����෴ 
	// maxEnd :
	// 0~i-1��Χ�ϣ�
	// �����������0��β�����е�����ۼӺ�
	// �����������1��β�����е�����ۼӺ�
	// ...
	// �����������i-1��β�����е�����ۼӺ�
	// ��������У������Ǹ��ۼӺ;���maxEnd
	int maxEnd = arr[0];
	for(int i = 1; i < n; i++){
		// maxend   i....
		// ö�ٻ��ֵ� i...
		ans = max(ans, maxEnd + start[i]);
		// �����������i��β�����е�����ۼӺ�
		end = max(arr[i], end + arr[i]);
		maxEnd = max(maxEnd, end);
	}
	// �п��ܲ��÷�ת��������һ�����Լ���ת�� 
	ans = max(ans, maxEnd);
	return ans;
}

int main()
{
	srand((unsigned)time(NULL));
	int testTime = 200;
	cout << "���Կ�ʼ" << endl;
	while(testTime--){
		n = rand() % 20;
		for(int i = 0; i < n; i++){
			arr[i] = rand() % 200 - 50;
		}
		int ans1 = maxSumReverse1(); // �е�С���� 
		int ans2 = maxSumReverse2();
		cout << ans1 << " " << ans2 << endl;
		if(ans1 != ans2){
			cout << "������" << endl;
		}
	}
	cout << "���Խ���" << endl;
	return 0;
}
