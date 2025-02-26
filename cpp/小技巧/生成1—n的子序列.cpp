#include <iostream> 
using namespace std;
#include <string>
#include <vector>
vector<vector<int>> ans;

// 方法一 
void dfs(vector<int> nums, int i, vector<int> tmp)
{
	if(i == nums.size()){
		ans.push_back(tmp);
		return ;
	}
	dfs(nums, i + 1, tmp);
	tmp.push_back(nums[i]);
	dfs(nums, i + 1, tmp);
	tmp.pop_back();
	return ;
}

void backTrack(vector<int> nums, int start, vector<int> tmp)
{
	ans.push_back(tmp);
	
	for(int i = start; i < nums.size(); i++){
		tmp.push_back(nums[i]);
		backTrack(nums, i + 1, tmp);
		tmp.pop_back();
	}
}

// 方法二
// 组合数（子集树） 
void subsets(vector<int> nums)
{
	vector<int> tmp;
	backTrack(nums, 0, tmp);
}


int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}
	vector<int> tmp;
	//dfs(nums, 0, tmp);
	subsets(nums);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
