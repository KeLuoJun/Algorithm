// ���鼯ģ��(���)
// ��ʵ���õݹ麯��ʵ��·��ѹ��������ʡ����С�Ҵ���Ż���һ������¿���ʡ��
// �������� : https://www.luogu.com.cn/problem/P3367


#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN = 10001;
int father[MAXN];
int n;

void build()
{
	for(int i = 0; i <= n; i++){
		father[i] = i;
	}
}

// �ݹ�ʵ�ֲ��鼯 
// ÿ���ڵ����һ�����Ǵ���ڵ� 
int find(int i)
{
	if(i != father[i]){
		father[i] = find(father[i]);
	}
	return father[i];
}

// �鿴x �� y �Ƿ���ͬһ�������� 
bool isSameSet(int x, int y)
{
	return find(x) == find(y);
}

void unions(int x, int y)
{
	father[find(x)] = find(y);
}



int main()
{
	int m;
	cin >> n >> m;
	int z,x,y;
	build();
	while(m--){
		cin >> z >> x >> y;
		if(z == 1){
			unions(x, y);
		}
		else if(z == 2){
			if(isSameSet(x, y))
				cout << "Y" << endl;
			else
				cout << "N" << endl;
		}
	}
	return 0;
}
