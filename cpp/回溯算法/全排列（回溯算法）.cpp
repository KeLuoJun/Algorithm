#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> ans;


// ������ 
void backTrack(vector<int> nums, vector<int> track, vector<bool> vis)
{
	// ����� nums.size() ����ָ���ĳ���k
	// �ͱ����Ԫ�ظ���Ϊ k ������ 
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
