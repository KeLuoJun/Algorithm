#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> ans;


// 排列树 
void backTrack(vector<int> nums, vector<int> track, vector<bool> vis)
{
	// 这里把 nums.size() 换成指定的长度k
	// 就变成求元素个数为 k 的排列 
	if(track.size() == nums.size()){
		ans.push_back(track);
		return;
	}
	
	for(int i = 0; i < nums.size(); i++){
		if(vis[i]){
			continue;
		}
		track.push_back(nums[i]);
		vis[i] = true;
		backTrack(nums, track, vis);
		track.pop_back();
		vis[i] = false;
	}
}
void permute(vector<int> nums)
{
	
	vector<int> track;
	vector<bool> vis(nums.size(), false);
	backTrack(nums, track, vis);
	
}

int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0, x; i < n; i++){
		cin >> x;
		nums[i] = x;
	}
	permute(nums);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < n; j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
	
}
