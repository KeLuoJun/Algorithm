// ����ƥ�䶨����ƥ���Ӵ�������
// ������Ϊn���ַ���s���Լ�����Ϊm���ַ���p������һ������k
// s'��sƥ��Ķ���Ϊ��s'��s������ͬ���������k��λ���ַ���ͬ
// Ҫ������ַ���s���ж����Ӵ����ַ���pƥ��
// �������� : https://www.luogu.com.cn/problem/P3763

#include <iostream>
#include <string>
using namespace std;
const int base = 499;
const int N = 100001;
int t;
long pow[N];
long hashs[N];
long hashp[N];


void build(string s, int n, string p, int m)
{
	// s��p���Թ���һ��pow 
	pow[0] = 1;
	for(int i = 1; i < N; i++){
		pow[i] = pow[i - 1] * base;
	}
	hashs[0] = s[0] - 'a' + 1;
	for(int i = 1; i < n; i++){
		hashs[i] = hashs[i - 1] * base + s[i] - 'a' + 1;
	}
	hashp[0] = p[0] - 'a' + 1;
	for(int i = 1; i < m; i++){
		hashp[i] = hashp[i - 1] * base + p[i] - 'a' + 1; 
	}
}

long getHash(long *hashed, int l, int r)
{
	long ans = hashed[r];
	if(l > 0){
		ans -= hashed[l - 1] * pow[r - l + 1];
	}
	return ans;
}

bool same(int l1, int l2, int len)
{
	return getHash(hashs, l1, l1 + len - 1) == getHash(hashp, l2, l2 + len - 1);
}

// s[l1...r1] �� p[0...m-1] ȡ�ȳ�������
// �������������ַ���һ����λ���ǲ���<=k��
// p[0...m-1] �����к����е�m����ͨ������ 
bool check(int l1, int r1, int k){
	int diff = 0;
	int l2 = 0;   // p�����λ�� 
	
	
	// ����Ķ���˼�����Ҫ
	while(l1 <= r1 && diff <= k){
		// l��rֻ�ǹ�������Ķ���λ�ã�ʵ�ʶ�Ӧ�ַ������±�Ϊ l+len �� r+len 
		int l = 1;
		int r = r1 - l1 + 1;
		int m, len = 0;
		// �����ҵ�����ߵĲ�ͬλ�� 
		while(l <= r){
			m = (l + r) / 2;
			if(same(l1, l2, m)){
				// ��ͬ�����len��m-1ȥ���� 
				len = m;
				l = m + 1;
			}else{
				r = m - 1;
			}
		}
		if(l1 + len <= r1){
			// ˵�� l1��len��һ����ͬ 
			diff++;
		}
		// ��len+1λ�ÿ�ʼ�����Ƚ� 
		l1 += len + 1;
		l2 += len + 1;
	}
	return diff <= k;
}


// s���ж����Ӵ��޸����k��λ�õ��ַ��Ϳ��Ա��p
// s����Ϊn��p����Ϊm��ʱ�临�Ӷ�O(n * k * logm)
int compute(string s, string p, int k)
{
	int n = s.size();
	int m = p.size();
	if(n < m) return 0;
	build(s, n, p, m);
	int ans = 0;
	for(int i = 0; i <= n - m; i++){
		// s[i...i+m-1] -> m
		// p[0.....m-1]
		if(check(i, i + m - 1, k)){
			ans++;
		}
	}
	return ans;
}


int main()
{
	cin >> t;
	for(int i = 0; i< t; i++){
		string s,p;
		cin >> s >> p;
		cout << compute(s, p, 3) << endl;
	}
	return 0;
} 



 
