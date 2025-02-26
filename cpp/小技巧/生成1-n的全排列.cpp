#include <iostream>  
#include <string>
using namespace std;  
const int MAXN = 1e5;
char sr[MAXN];
int vis[MAXN] = {0};

//生成向量的所有排列
void permute1(string str, int left, int right)
{
     //如果遍历到 left == right ，说明全排列已经做完了只需输出即可
    if (left == right) 
        cout<<str<<endl;
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

// 深搜的方法 
void permute2(string s, int i)
{
	if(i == s.size()){
		for(int j = 0; j < s.size(); j++){
			cout << sr[j];
		}
		cout << endl;
		return;
	}
	for(int j = 0; j < s.size(); j++){
		if(!vis[j]){
			vis[j] = 1;
			sr[i] = s[j];
			permute2(s, i + 1);
			vis[j] = 0;
		}
	}
}

int main() 
{
    string str = "114514";
    int size = str.size();
    //permute1(str, 0, size-1);
    permute2(str, 0);
    return 0;
}
