// ���Բ�������Ƶ������������
// ����һ���������� nums ����һ����ʾ���Ƶ����� limit
// ���㷵�������������ĳ���
// ���������е���������Ԫ��֮��ľ��Բ����С�ڻ��ߵ��� limit
// ������������������������飬�򷵻� 0
// �������� : https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

#include <iostream>
using namespace std;
const int N = 100001;
int n, limit;
int arr[N];
// ���������ֵ�ĸ��½ṹ���������У�
int maxdq[N];
// ��������Сֵ�ĸ��½ṹ���������У�
int mindq[N];
int maxh, maxt, minh, mint;


// �ж������������number���������ֵ - ������Сֵ�Ƿ���Ȼ <= limit
// ��Ȼ <= limit������true
// ���� <= limit������false
bool ok(int num)
{
	// maxnum : ���number�������´��ڵ����ֵ
	int maxnum = maxh < maxt ? max(arr[maxdq[maxh]], num) : num;
	// minnum : ���number�������´��ڵ���Сֵ
	int minnum = minh < mint ? min(arr[mindq[minh]], num) : num;
	return maxnum - minnum <= limit;
}

// rλ�õ����ֽ��봰�ڣ��޸Ĵ��������ֵ�ĸ��½ṹ���޸Ĵ�������Сֵ�ĸ��½ṹ
void push(int r)
{
	while(maxh < maxt && arr[maxdq[maxt - 1]] <= arr[r]){
		maxt--;
	}
	maxdq[maxt++] = r;
	while(minh < mint && arr[mindq[mint - 1]] >= arr[r]){
		mint--;
	}
	mindq[mint++] = r;
}

// ����Ҫ�³�lλ�õ����ˣ������ڣ�
void pop(int l)
{
	if(maxh < maxt && maxdq[maxh] == l){
		maxh++;
	}
	if(minh < mint && mindq[minh] == l){
		minh++;
	}
}


int longestSubarray()
{
	maxh = maxt = minh = mint = 0;
	int ans = 0;
	for(int l = 0, r = 0; l < n; l++){
		// [l,r)��r��Զ��û�н��봰�ڵġ���һ�������ڵ�λ��
		while(r < n && ok(arr[r])){
			push(r++);
		}
		// ��while������ʱ��[l,r)��l��ͷ����������������������Χ
		ans = max(ans, r - l);
		pop(l);
	}
	return ans;
}



int main()
{
	cin >> n >> limit;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int ans = longestSubarray();
	cout << ans << endl;
	return 0;
}
