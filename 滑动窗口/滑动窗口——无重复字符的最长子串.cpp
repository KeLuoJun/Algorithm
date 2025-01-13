#include <iostream>
using namespace std;
#include <string>

int main()
{
	string s;
	cin >> s;
	int last[26] = {-1};  //存储对于字符最新出现的位置 
	int ans = 0;
	for(int l = 0,r = 0; r < s.size(); r++)
	{
		//判断子串中的字符是否与将要进入的r处的字符重复
		//若重复，l更新到子串中字符与r处字符重复的下一个位置 
		l = max(l,last[s[r] - 'a'] + 1);
		ans = ans > r - l + 1 ? ans : r - l + 1;
		last[s[r] - 'a'] = r;  //更新位置 
	}
	cout << ans << endl;
	return 0;
}
