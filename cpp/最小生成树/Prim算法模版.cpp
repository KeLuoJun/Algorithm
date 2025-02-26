// 1、解锁的点的集合叫set（普通集合）、解锁的边的集合叫heap（小根堆）
// set和heap都为空
// 2、可以从任意点开始，开始点加入到set中，开始点的所有边加入到heap中
// 3、从heap中弹出权值最小的边e，查看边e所去往的点x
//    A、如果x已经在set中，边e舍弃，重复步骤3
//    B、如果x不在set中，边e属于最小生成树，吧x加入set，重复步骤3
// 4、当heap为空，得到最小生成树 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 定义最大顶点数量
int MaxVexNum = 10;
int n;   // 点的个数 

// 存储边的数组，每个元素为{起点，终点，权重}
int edges[11][3] = {{1, 2, 4}, {2, 0, 8}, {2, 5, 9}, {3, 5, 6}, {3, 2, 5},
					{4, 3, 5}, {5, 4, 1}, {5, 0, 3}, {0, 5, 3}, {0, 1, 5}, {0, 3, 7}};
						  
// 图的邻接表，使用三维向量存储，方便表示边的信息（终点，权重）
vector<vector<vector<int>>> graph(MaxVexNum);

// 建立图的邻接表
void build()
{
	for(const auto& edge : edges){
		// 将每条边的信息存入对应的起点的邻接表中
		graph[edge[0]].push_back({edge[1], edge[2]});
	}
	// 设置顶点总数
	n = 6;
}

// 打印图的邻接表
void showGraph()
{
	cout << "图的邻接表为：" << endl;
	for(int i = 0; i < n; i++){
		cout << i; // 打印当前顶点编号
		// 遍历该顶点的所有出边并打印
		for(const auto& edge : graph[i]){
			cout << " --(" << edge[1] << ")-->" << edge[0]; 
		}
		cout << endl; // 换行
	}
}

// 自定义比较器，用于小根堆，按边的权重排序
struct Compare{
	bool operator()(const vector<int>&a, const vector<int>&b){
		return a[2] > b[2]; // 如果a的权重大于b的权重，则a在b之前（大顶堆），这里用于priority_queue需要颠倒比较逻辑实现小顶堆
	}
};

// Prim算法实现最小生成树
vector<vector<int>> PrimAlgorithm()
{
	// 使用优先队列（小根堆）存储待处理的边
	priority_queue<vector<int>, vector<vector<int>>, Compare> heap;
	// 初始化已加入最小生成树的顶点集合
	vector<bool> set(n, false);
	// 初始化已加入最小生成树的顶点计数
	int nodeCnt = 1;
	// 将起点加入集合
	set[0] = true;
	// 将起点的所有出边加入堆中
	for(const auto& edge : graph[0]){
		heap.push(edge);
	}
	// 存储最小生成树的结果
	vector<vector<int>> ans;
	// 添加起始点到结果中，权值设为0（起始点）
	ans.push_back({0, 0});
	// 循环直到所有顶点都被加入最小生成树
	while(!heap.empty()){
		// 取出权值最小的边
		int next = heap.top()[0];
		int cost = heap.top()[1];
		heap.pop();
		// 如果该边的终点未加入最小生成树
		if(!set[next]){
			// 加入新顶点
			nodeCnt++;
			set[next] = true;
			// 将这条边加入结果
			ans.push_back({next, cost});
			// 将新加入顶点的所有出边加入堆中
			for(const auto& e : graph[next]){
				heap.push(e);
			}
		}
	}
	return ans;
} 

// 主函数
int main()
{
	// 构建图
	build();
	// 显示图的邻接表
	showGraph();
	// 运行Prim算法并获取最小生成树
	vector<vector<int>> ans = PrimAlgorithm();
	cout << endl;
	cout << "最小生成树：" << endl;
	// 打印最小生成树的边
	for(int i = 0; i < ans.size(); i++){
		// 起始点不打印连接符和权值
		if(ans[i][1] == 0){
			cout << ans[i][0];
		}else{
			cout << " --(" << ans[i][1] << ")-->" << ans[i][0]; 
		}
	}
	return 0;
}	  
