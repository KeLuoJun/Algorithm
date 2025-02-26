// ���鼯ģ��(ţ��)
// ·��ѹ�� + С�Ҵ�
// �������� : https://www.nowcoder.com/practice/e7ed657974934a30b2010046536a5372

#include <iostream>
using namespace std;
typedef long long ll;
const ll MAXN = 1000001;
ll *father = new ll[MAXN];
ll *sizes = new ll[MAXN]; 
ll *stack = new ll[MAXN];
ll n;

void build()
{
	for(ll i = 0; i <= n; i++){
		father[i] = i;
		sizes[i] = 1;
	}
}

// i�Žڵ㣬����һֱ�ң��ҵ�����ڵ㷵�أ�
ll find(ll i)
{
	// ��;�ռ��˼�����
	ll size = 0;
	while(i != father[i]){
		stack[size++] = i;
		i = father[i];
	}
	// ��;�ڵ��ռ����ˣ�i�Ѿ���������ڵ���
	while(size > 0){
		father[stack[--size]] = i;
	}
	return i;
}


bool isSameSet(ll x, ll y)
{
	return find(x) == find(y);
 } 
 
void unions(ll x, ll y)
{
	ll fx = find(x);
	ll fy = find(y);
	if(fx != fy){
		// fx�Ǽ��ϵĴ����ô�С
		// fy�Ǽ��ϵĴ����ô�С
		if(sizes[fx] >= sizes[fy]){
			sizes[fx] += sizes[fy];
			father[fy] = fx;
		}
		else{
			sizes[fy] += sizes[fx];
			father[fx] = fy;
		}
	}
}


int main()
{
	ll m;
	cin >> n >> m;
	ll opt,x,y;
	build();
	while(m--){
		cin >> opt >> x >> y;
		if(opt == 1){
			if(isSameSet(x, y))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else if(opt == 2){
			unions(x, y);
		}
	}
	return 0;
}
