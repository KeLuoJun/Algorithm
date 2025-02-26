// �ַ�����ϣ�õ��Ӵ���ϣ
// �����ַ�����ϣ�ı��������KMP�㷨
// �������� : https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include <iostream>
#include <string>
using namespace std;
const int base = 499;
const int N = 100005;
long pow[N];     // ÿһλ��Ӧbase�Ķ��ٴη� 
long hashs[N];   // �ַ��� 0-i ��Ӧ�Ĺ�ϣֵ 


// ���´������ַ�����ϣ��ԭ���ģ��
// ���磬base = 499, Ҳ���ǿ���˵��ѡ�����������
// �ٱ����ַ���s����
// " c a b e f "
//   0 1 2 3 4
// hash[0] = 3 * base��0�η�
// hash[1] = 3 * base��1�η� + 1 * base��0�η�
// hash[2] = 3 * base��2�η� + 1 * base��1�η� + 2 * base��0�η�
// hash[3] = 3 * base��3�η� + 1 * base��2�η� + 2 * base��1�η� + 5 * base��0�η�
// hash[4] = 3 * base��4�η� + 1 * base��3�η� + 2 * base��2�η� + 5 * base��1�η� + 6 *
// base��0�η�
// hash[i] = hash[i-1] * base + s[i] - 'a' + 1����������˵����˼
// ������Ӵ�"be"�Ĺ�ϣֵ -> 2 * base��1�η� + 5 * base��0�η�
// �Ӵ�"be"�Ĺ�ϣֵ = hash[3] - hash[1] * base��2�η�(�Ӵ�"be"�ĳ��ȴη�)
// hash[1] = 3 * base��1�η� + 1 * base��0�η�
// hash[1] * base��2�η� = 3 * base��3�η� + 1 * base��2�η�
// hash[3] = 3 * base��3�η� + 1 * base��2�η� + 2 * base��1�η� + 5 * base��0�η�
// hash[3] - hash[1] * base��2�η� = 2 * base��1�η� + 5 * base��0�η�
// �����͵õ��Ӵ�"be"�Ĺ�ϣֵ��
// �Ӵ�s[l...r]�Ĺ�ϣֵ = hash[r] - hash[l-1] * base��(r-l+1)�η�����������˵����˼
void build(string s, int n)
{
	pow[0] = 1;
	for(int i = 1; i < n; i++){
		pow[i] = pow[i - 1] * base;
	}
	hashs[0] = s[0] - 'a' + 1;
	for(int i  = 1; i < n; i++){
		hashs[i] = hashs[i - 1] * base + s[i] - 'a' + 1;
	}
}

long getHash(int l, int r)
{
	long ans = hashs[r];
	if(l > 0){
		ans -= hashs[l - 1] * pow[r - l + 1];
	}
	return ans;
}


int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.size();
	int m = s2.size();
	build(s1, n);
	long h2 = s2[0] - 'a' + 1;  // h2 Ϊs2�Ĺ�ϣֵ 
	for(int i = 1; i < m; i++){
		h2 = h2 * base + s2[i] - 'a' + 1;
	}
	// �������� 
	int ans = -1;
	for(int l = 0, r = m - 1; r < n; l++, r++){
		if(getHash(l, r) == h2){
			ans = l;
			break;
		}
	}
	cout << ans << endl;
	return 0;
 } 
