// h题 

#include <iostream> 
using namespace std;
#include <string>
int n;
string s;
int ans = 0;


bool check(string str)
{
    int len = str.size();
    for(int i = 0; i <= len/2; i++){
        if(str[i] != str[len - i - 1]){
            return false;
        }
    }
    return true;
}

// 全排列
void permute1(string str, int left, int right)
{
     //如果遍历到 left == right ，说明全排列已经做完了只需输出即可
    if (left == right) 
        cout<<str<<endl;
        if(check(str)){
            ans++;
        }
    else {
        // 递归情况：生成剩余元素的排列
        for (int i = left; i <= right; i++) 
        {
            // 将当前元素与第一个元素交换
            // 保持第一个元素固定并生成其余元素的排列
            swap(str[left], str[i]);
            // 递归调用
            permute1(str, left+1, right);
            //进行回溯
            swap(str[left], str[i]);
        }
    }
}

// 子序列
void dfs(int i, int n, string str)
{
	if(i == n){
		//cout << str << endl;
		permute1(str, 0, str.size() - 1);
		return ;
	}
	dfs(i + 1, n, str);
	dfs(i + 1, n, str + s[i]);
	return ;
}




int main()
{
	cin >> n;
	cin >> s;
	dfs(0, n, "");
	cout << ans << endl;
	return 0;
}
