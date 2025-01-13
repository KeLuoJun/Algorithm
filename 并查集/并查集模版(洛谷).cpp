// 并查集模版(洛谷)
// 本实现用递归函数实现路径压缩，而且省掉了小挂大的优化，一般情况下可以省略
// 测试链接 : https://www.luogu.com.cn/problem/P3367


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

// 递归实现并查集 
// 每个节点的上一级都是代表节点 
int find(int i)
{
	if(i != father[i]){
		father[i] = find(father[i]);
	}
	return father[i];
}

// 查看x 和 y 是否在同一个集合里 
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
