// ��ҽ��� IV
// �ؽ���һ�������ķ��ݡ�ÿ�䷿���ڶ�����һ�����ֽ�
// ������һλС͵�ƻ�����Щ��������ȡ�ֽ�
// �������ڵķ���װ���໥��ͨ�ķ���ϵͳ������С͵������ȡ���ڵķ���
// С͵�� ��ȡ���� ����Ϊ������ȡ�������ܴӵ��䷿������ȡ�� �����
// ����һ���������� nums ��ʾÿ�䷿�ݴ�ŵ��ֽ���
// ��i�䷿���з���nums[i]��Ǯ��
// �����һ������k����ʾС͵��Ҫ��ȡ���� k �䷿��
// ����С͵��Ҫ����С��ȡ����ֵ
// �������� : https://leetcode.cn/problems/house-robber-iv/

#include <iostream>
using namespace std;
const int MAXN = 1e5 + 1;
int *nums = new int[MAXN];
int n,k;

int mostRob1(int ability)
{
	if(n == 1)
		return nums[0] <= ability ? 1 : 0;
	if(n == 2)
		return max(nums[0] <= ability ? 1 : 0, nums[1] <= ability ? 1 : 0);
	// ��ʱ��prepre �� pre ��ʾ�����ڵ�ǰλ���������õ����ֵ�������������������ֵ��ۼ�ֵ 
	int prepre = nums[0] <= ability ? 1 : 0;
	int pre = nums[1] <= ability ? 1 : 0;
	for(int i = 2,cur; i < n; i++){
		cur = max(pre, (nums[i] <= ability ? 1 : 0) + prepre);
		prepre = pre;
		pre = cur; 
	}
	return pre;
}


// ����̰���Ż�
// ��Ϊ����ֻ��Ҫ�����������������nums[i]������������õ��������������������ۼӺ�
// ��ֻҪ����nums[i] < ability�����֣�ֱ���ã�����Ϊ�����ڳ������ȡֵ�ռ�
// �����׻�ø�������� 
int mostRob2(int ability)
{
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(nums[i] <= ability)
			ans++;
			i++;
	}
	return ans;
}


int minCapability()
{
	int l = nums[0], r = nums[0];
	for(int i = 1; i < n; i++){
		l = min(l, nums[i]);
		r = max(r, nums[i]);
	}
	int ans = 0;
	while(l <= r){
		int m = l + ((r - l) >> 1);
		if(mostRob2(m) >= k){
			ans = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	return ans;
}

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	
	cout << minCapability() << endl;
	return 0;
}
