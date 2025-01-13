// �����ַ�����
// ��������ַ��� X �е�������ͬλ�õ���ĸ��ʹ�������ַ��� Y ���
// ��ô�� X �� Y �����ַ�������
// ����������ַ�����������ȵģ�������Ҳ�����Ƶ�
// ���磬"tars" �� "rats" �����Ƶ� (���� 0 �� 2 ��λ��)��
// "rats" �� "arts" Ҳ�����Ƶģ����� "star" ���� "tars"��"rats"���� "arts" ����
// ��֮������ͨ���������γ������������飺{"tars", "rats", "arts"} �� {"star"}
// ע�⣬"tars" �� "arts" ����ͬһ���У���ʹ���ǲ�������
// ��ʽ�ϣ���ÿ������ԣ�Ҫȷ��һ�����������У�ֻ��Ҫ����ʺ͸���������һ���������ơ�
// ����һ���ַ����б� strs�б��е�ÿ���ַ������� strs �����������ַ�����һ����ĸ��λ�ʡ�
// ���� strs ���ж����ַ�����
// �������� : https://leetcode.cn/problems/similar-string-groups/


#include <iostream>
#include <string>
using namespace std;

const int MAXN = 301;
int *father = new int[MAXN];
int sets;   // ���鼯���ϵ����� 
int n;

void build(int m)
{
	for(int i = 0; i < m; i++)
		father[i] = i;
	sets = 0;
}

int find(int i)
{
	if(i != father[i]){
		father[i] = find(father[i]);
	}
	return father[i];
}


void unions(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy){
		father[fx] = fy;
		sets++;
	}
}


int main()
{
	cin >> n;
	string s[n];
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	build(n);
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			int diff = 0;
			// ������Ѿ���ͬһ����������ģ���֤�������������ַ�����ֱ������ 
			if(find(i) != find(j)){
				for(int k = 0; k < s[i].size(); k++){
					if(s[i][k] != s[j][k])
						diff++;
				}
			}
			// ���������ַ��� 
			if(diff == 0 || diff == 2){
				unions(i, j);
			}
		}
	}
	cout << sets << endl;
	return 0;
}
