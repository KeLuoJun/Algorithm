// 运算类似 1+(2+3)*3 的结果 
// 测试链接 : https://leetcode.cn/problems/basic-calculator-iii/

#include <iostream>
using namespace std;
#include <vector>
#include <string>
int where = 0;

void push(vector<int> &numbers, vector<char> &ops, int cur, char op)
{
	int n = numbers.size();
	//容器为空 或者 运算符容器的最顶上的运算符为 + -，直接放入数字和运算符 
	if(n == 0 || ops.back() == '+' || ops.back() == '-')
	{
		numbers.push_back(cur);
		ops.push_back(op);
	}
	else
	{
		//先取出最顶上的数字和运算符，将最顶上的数字 * 或 / 最新要加入的数字
		//再放入数字容器的顶端，新的运算符也放放入运算符容器的顶端 
		int topNum = numbers.back();
		char topOp = ops.back();
		if(topOp == '*')
		{
			numbers.back() = topNum * cur;
		}
		else
		{
			numbers.back() = topNum / cur;
		}
		ops.back() = op;
	}
}

int compute(vector<int> &numbers, vector<char> &ops)
{
	int ans = numbers[0];  //数字容器的底下数字 
	int n = numbers.size();
	for(int i = 1; i < n; i++)
	{
		ans += (ops[i - 1] == '+' ? numbers[i] : -numbers[i]);
	}
	return ans;
}

//s[i......] 开始计算，遇到字符串终止 或者 遇到 ')' 停止
//返回：自己负责的这一段，计算的结果
//返回之间，更新全局变量where，为了上游函数知道从哪继续 


int f(string s,int i)
{
	int cur = 0;
	vector<int> numbers;
	vector<char> ops;
	while(i < s.size() && s[i] != ')')
	{
		if(s[i] >= '0' && s[i] <= '9')
			cur = cur * 10 + (int)(s[i++] - '0');
		else if(s[i] != '(')
		//遇到了运算符 + - * / 
		{
			//处理数字容器 和 运算符容器 
			push(numbers, ops, cur, s[i++]);
			cur = 0;
		} 
		else
		{
			//遇到了左括号 
			cur = f(s,i+1);
			i = where + 1;  //从右括号的下一个字符串开始继续上一层递归函数的递归过程 
		}
	}
	//遇到 右括号')' 停止递归 并把递归的这段结果放回和更新递归的终止位置 
	push(numbers, ops, cur, '+');  //遇到右括号，默认运算符为 + 号 
	where = i;
	return compute(numbers, ops);
}

int main()
{
	string s;
	cin >> s;
	int ans = f(s,0);
	cout << ans << endl;
	return 0;
} 
