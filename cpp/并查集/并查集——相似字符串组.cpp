// 相似字符串组
// 如果交换字符串 X 中的两个不同位置的字母，使得它和字符串 Y 相等
// 那么称 X 和 Y 两个字符串相似
// 如果这两个字符串本身是相等的，那它们也是相似的
// 例如，"tars" 和 "rats" 是相似的 (交换 0 与 2 的位置)；
// "rats" 和 "arts" 也是相似的，但是 "star" 不与 "tars"，"rats"，或 "arts" 相似
// 总之，它们通过相似性形成了两个关联组：{"tars", "rats", "arts"} 和 {"star"}
// 注意，"tars" 和 "arts" 是在同一组中，即使它们并不相似
// 形式上，对每个组而言，要确定一个单词在组中，只需要这个词和该组中至少一个单词相似。
// 给你一个字符串列表 strs列表中的每个字符串都是 strs 中其它所有字符串的一个字母异位词。
// 返回 strs 中有多少字符串组
// 测试链接 : https://leetcode.cn/problems/similar-string-groups/


#include <iostream>
#include <string>
using namespace std;

const int MAXN = 301;
int *father = new int[MAXN];
int sets;   // 并查集集合的数量 
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
			// 如果是已经在同一个集合里面的，就证明两者是相似字符串，直接跳过 
			if(find(i) != find(j)){
				for(int k = 0; k < s[i].size(); k++){
					if(s[i][k] != s[j][k])
						diff++;
				}
			}
			// 属于相似字符串 
			if(diff == 0 || diff == 2){
				unions(i, j);
			}
		}
	}
	cout << sets << endl;
	return 0;
}
