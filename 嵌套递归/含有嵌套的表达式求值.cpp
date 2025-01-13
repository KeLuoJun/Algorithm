// �������� 1+(2+3)*3 �Ľ�� 
// �������� : https://leetcode.cn/problems/basic-calculator-iii/

#include <iostream>
using namespace std;
#include <vector>
#include <string>
int where = 0;

void push(vector<int> &numbers, vector<char> &ops, int cur, char op)
{
	int n = numbers.size();
	//����Ϊ�� ���� �������������ϵ������Ϊ + -��ֱ�ӷ������ֺ������ 
	if(n == 0 || ops.back() == '+' || ops.back() == '-')
	{
		numbers.push_back(cur);
		ops.push_back(op);
	}
	else
	{
		//��ȡ����ϵ����ֺ������������ϵ����� * �� / ����Ҫ���������
		//�ٷ������������Ķ��ˣ��µ������Ҳ�ŷ�������������Ķ��� 
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
	int ans = numbers[0];  //���������ĵ������� 
	int n = numbers.size();
	for(int i = 1; i < n; i++)
	{
		ans += (ops[i - 1] == '+' ? numbers[i] : -numbers[i]);
	}
	return ans;
}

//s[i......] ��ʼ���㣬�����ַ�����ֹ ���� ���� ')' ֹͣ
//���أ��Լ��������һ�Σ�����Ľ��
//����֮�䣬����ȫ�ֱ���where��Ϊ�����κ���֪�����ļ��� 


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
		//����������� + - * / 
		{
			//������������ �� ��������� 
			push(numbers, ops, cur, s[i++]);
			cur = 0;
		} 
		else
		{
			//������������ 
			cur = f(s,i+1);
			i = where + 1;  //�������ŵ���һ���ַ�����ʼ������һ��ݹ麯���ĵݹ���� 
		}
	}
	//���� ������')' ֹͣ�ݹ� ���ѵݹ����ν���Żغ͸��µݹ����ֹλ�� 
	push(numbers, ops, cur, '+');  //���������ţ�Ĭ�������Ϊ + �� 
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
