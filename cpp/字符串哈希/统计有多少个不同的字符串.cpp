// ͳ���ж��ٸ���ͬ���ַ���
// �������� : https://www.luogu.com.cn/problem/P3370

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N = 10001;
const int base = 499;
long nums[N];   // �� long���ȣ�������Ȼ�Ƴ����൱�� %long �Ľ�� 
int n;

// �õ��ַ�����Ӧ������ 
// ���� + ��д + Сд
// '0' -> 1
// '1' -> 2
// ...
// '9' -> 10
// 'A' -> 11
// 'B' -> 12
// ...
// 'Z' -> 36
// 'a' -> 37
// ...
// 'z' -> 62
int v(char c)
{
	// ע���ַ���Ӧ�ı�����ʼֵ������0 
	if(c >= '0' && c <= '9'){
		return c - '0' + 1;
	}else if(c >= 'A' && c <= 'Z'){
		return c - 'A' + 11;
	}else{
		return c - 'a' + 37;
	}
}


// ��Ҫ���� 
// �õ��ַ����Ĺ�ϣֵ 
long value(string s)
{
	long ans = v(s[0]);
	for(int i = 1; i < s.size(); i++){
		ans = ans * base + v(s[i]);
	}
	return ans;
}

// �����ַ����Ĺ�ϣֵ�ж��Ƿ����ظ����ַ��� 
int cnt()
{
	sort(nums, nums + n);
	int ans = 1;
	for(int i = 1; i < n; i++){
		if(nums[i] != nums[i - 1]){
			ans++;
		}
	}
	return ans;
} 


int main()
{
	cin >> n;
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		nums[i] = value(s);
	}
	int ans = cnt();
	cout << ans << endl;
	return 0;
}
