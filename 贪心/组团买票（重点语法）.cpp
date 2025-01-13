// 组团买票
// 景区里一共有m个项目，景区的第i个项目有如下两个参数：
// game[i] = { Ki, Bi }，Ki、Bi一定是正数
// Ki代表折扣系数，Bi代表票价
// 举个例子 : Ki = 2, Bi = 10
// 如果只有1个人买票，单张门票的价格为 : Bi - Ki * 1 = 8
// 所以这1个人游玩该项目要花8元
// 如果有2个人买票，单张门票的价格为 : Bi - Ki * 2 = 6
// 所以这2个人游玩该项目要花6 * 2 = 12元
// 如果有5个人买票，单张门票的价格为 : Bi - Ki * 5 = 0
// 所以这5个人游玩该项目要花5 * 0 = 0元
// 如果有更多人买票，都认为花0元(因为让项目倒贴钱实在是太操蛋了)
// 于是可以认为，如果有x个人买票，单张门票的价格为 : Bi - Ki * x
// x个人游玩这个项目的总花费是 : max { x * (Bi - Ki * x), 0 }
// 单位一共有n个人，每个人最多可以选1个项目来游玩，也可以不选任何项目
// 所有员工将在明晚提交选择，然后由你去按照上面的规则，统一花钱购票
// 你想知道自己需要准备多少钱，就可以应付所有可能的情况，返回这个最保险的钱数
// 数据量描述 : 
// 1 <= M、N、Ki、Bi <= 10^5
// 来自真实大厂笔试，没有在线测试，对数器验证


#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5;

// 暴力方法
// 为了验证
// 每个人做出所有可能的选择
// 时间复杂度O((m+1)的n次方)
int f(int i, int n, int m, int (*game)[2], int *cnts)
{
	if(i == n){
		int ans = 0;
		for(int j = 0; j < m; j++){
			int k = game[j][0];
			int b = game[j][1];
			int x = cnts[j];
			ans += max((b - k * x) * x, 0);
		}
		return ans;
	}else{
		int ans = f(i + 1, n, m, game, cnts);
		for(int j = 0; j < m; j++){
			cnts[j]++;
			ans = max(ans, f(i + 1, n, m, game, cnts));
			cnts[j]--;
		}
		return ans;
	}
}

int enough1(int n, int m, int (*game)[2])
{
	int *cnts = new int[m];
	// 存储每个项目去的人数 
	memset(cnts, 0, sizeof(cnts));
	return f(0, n, m, game, cnts);
}



// 正式方法
// 时间复杂度O(n * logm)
struct Game{
	int ki;
	int bi;
	int people;
	
	Game(int k, int b){
		ki = k;  // 折扣系数 
		bi = b;  // 门票价格 
		people = 0;  // 之前的人数 
	}
	// 如果再来一人，这个项目得到多少钱
	int earn() const {
		// bi - (people + 1) * ki : 当前的人，门票原价减少了，当前的门票价格  
        // people * ki : 当前人的到来，之前的所有人，门票价格都再减去ki  
		return bi - (people + 1) * ki - people * ki;
	}
};

struct Compare{
	 // 大根堆，所以返回b.earn() > a.earn()  
	bool operator()(const Game& a, const Game& b){
		return b.earn() > a.earn();
	}
};

int enough2(int n, int m, int (*game)[2])
{
	// 哪个项目，再来一人挣得最多  
    // 大根堆  
	priority_queue<Game, vector<Game>, Compare> heap;
	for(int i = 0; i < m; i++){
		// 拔game中的数据初始化进Game后放入大根堆 
		heap.push(Game(game[i][0], game[i][1]));
	}
	int ans = 0;
	for(int i = 0; i < m; i++){
		// 一个个的人，依次送到当前最挣钱的项目里去
		if(heap.top().earn() < 0){
			break;
		}
		Game cur = heap.top();
		heap.pop();
		ans += cur.earn();
		cur.people++;
		heap.push(cur);
	}
	return ans;
}


int main()
{
	int n,m;
	srand((unsigned)time(NULL));
	int (*game)[2] = new int[MAXN][2];
	n = rand() % MAXN;
	m = rand() % MAXN; 
//	cin >> n >> m;
//	for(int i = 0; i < m; i++){
//		cin >> game[i][0] >> game[i][1];
//	}
	for(int i = 0; i < m; i++){
		game[i][0] = rand() % MAXN;
		game[i][0] = rand() % MAXN;
	}
	cout << enough1(n, m, game) << endl;
	cout << enough2(n, m, game) << endl;
	return 0;
	
}
