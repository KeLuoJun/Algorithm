// �������ص������������
// ����һ���������� nums ��һ������ k
// �ҳ���������Ϊ k �������ص�����ȫ�����ֺͣ�3 * k �����������
// ������������������
// ���±��������ʽ���ؽ���������е�ÿһ��ֱ�ָʾÿ�����������ʼλ��
// ����ж������������ֵ�����С��һ��
// �������� : https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays/


#include <iostream>
using namespace std;
const int N = 1e5;
int n, k;
int arr[N];
int a, b, c;

void maxSumOfThreeSubarrays()
{
	// sums[i] : ��i��ͷ���ҳ���Ϊk����������ۼӺ�
	int *sums = new int[n];
	for(int l = 0, r = 0, sum = 0; r < n; r++){
		// l....r
		sum += arr[r];
		if(r - l + 1 == k){
			sums[l] = sum;
			sum -= arr[l];
			l++;
		}
	}
	// prefix[i] :
	// 0~i��Χ�����г���Ϊk���������У�ӵ������ۼӺ͵������飬����ʲôλ�ÿ�ͷ��
	// example: k = 3
	// prefix[0]: 0..0  ����k��
	// prefix[1]: 0..1  ����k��
	// prefix[2]: 0..2  ��k����Ҳ��ֱ����0
	// prefix[3]: prefix[i-1]  ��ǰ�������pk 
	int *prefix = new int[n];
	for(int i = 0; i < k; i++){
		prefix[i] = 0;
	}
	// lΪ��ǰk�������ʼ�㣬rΪ��ǰk�����ĩ��
	// ����Ϊ sums ���� l Ϊ����ҳ���Ϊk�ĺͣ� 
	for(int l = 1, r = k; r < n; l++, r++){
		if(sums[l] > sums[prefix[r - 1]]){
		// ע��>��Ϊ��ͬ������ۼӺ͵�����£���С���ֵ���
			prefix[r] = l;
		}else{
			prefix[r] = prefix[r - 1];
		}
	}
	
	// suffix[i] :
	// i~n-1��Χ�����г���Ϊk���������У�ӵ������ۼӺ͵������飬����ʲôλ�ÿ�ͷ��
	int *suffix = new int[n];
	suffix[n - k] = n - k;
	for(int l = n - k - 1; l >= 0; l--){
		if(sums[l] >= sums[suffix[l + 1]]){
		// ע��>=��Ϊ��ͬ������ۼӺ͵�����£���С���ֵ���
			suffix[l] = l;
		}else{
			suffix[l] = suffix[l + 1];
		}
	}
	int ans = 0;
	//    a         b          c 
	// 0...i-1    i...j    j+1...n-1
	//   ��     ��(����Ϊk)     ��
	for(int p, s, i = k, j = 2 * k - 1, sum; j < n - k; i++, j++){
		// 0.....i-1     i.....j   j+1.....n-1
		// ��ÿ�ͷp      i��ͷ     ��ÿ�ͷs
		p = prefix[i - 1];
		s = suffix[j + 1];
		sum = sums[p] + sums[i] + sums[s];
		if(sum > ans){
			// ע��>��Ϊ��ͬ������ۼӺ͵�����£���С���ֵ���
			ans = sum;
			a = p;
			b = i;
			c = s;
		}
	}
}


int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	maxSumOfThreeSubarrays();
	cout << a << " " << b << " " << c << endl;
	return 0;
}
