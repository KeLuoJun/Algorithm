// ��С�ı�Ҫ�Ŷ�
// ��Ϊ��Ŀ������滮��һ������ļ����嵥req_skills
// ������ӱ�ѡ��Ա����people��ѡ��Щ����ɱ�Ҫ�Ŷ�
// ���Ϊi�ı�ѡ��Աpeople[i]����һ�ݸñ�ѡ��Ա���յļ����б�
// ��ν��Ҫ�Ŷӣ�����������Ŷ���
// ����������ļ����б�req_skills���г���ÿ��ܣ��Ŷ���������һ����Ա�Ѿ�����
// ���㷵�ع�ģ��С�ı�Ҫ�Ŷӣ��Ŷӳ�Ա����Ա��ű�ʾ
// ����԰� ����˳�� ���ش𰸣���Ŀ���ݱ�֤�𰸴���
// �������� : https://leetcode.cn/problems/smallest-sufficient-team/

#include <iostream>
#include <map>
using namespace std;
const int MAXN = 17;
const int MAXM = 61;
string skills;
int n, m;
int num[MAXM];
int arr[MAXN];
map<string, int> mm;

// arr : ÿ���������յı�Ҫ���ܵ�״̬
// m : �˵�����
// n : ��Ҫ���ܵ�����
// i : ��ǰ�����ڼ�����
// s : ��Ҫ���ܸ��ǵ�״̬
// ���� : i....��Щ�ˣ��ѱ�Ҫ���ܶ����룬������Ҫ������
int f(int *arr, int i, int s, int (*dp)[MAXM])
{
	if(s == (1 << n) - 1)
	// ���м����Ѿ�������
		return 0;
	// û����
	if(i == n)
	// ���Ѿ�û�ˣ�����Ҳû����
	// ��Ч
		return INT_MAX;
	if(dp[i][s] != -1)
		return dp[i][s];
	// ������1 : ��Ҫi����
	int p1 = f(arr, i + 1, s, dp);
	// ������2 : Ҫi����
	int p2 = INT_MAX;
	int next2 = f(arr, i + 1, s | arr[i], dp);
	if(next2 != INT_MAX){
		// ������Ч
		p2 = 1 + next2;
	}
	int ans = min(p1, p2);
	dp[i][s] = ans;
	return ans;
}

int main()
{
	cout << "���������輼�ܵ�����:";
	cin >> n;
	cout << "���������輼��:" ; 
	for(int i = 0; i < n; i++){
		// �����б�Ҫ�������α��
		cin >> skills;
		mm.insert(make_pair(skills, i));
	}
	cout << "�������˵�����:" ;
	cin >> m;
	// arr[i] : ��i�������ձ�Ҫ���ܵ�״������λ��Ϣ��ʾ
	for(int i = 0; i < m; i++){
		cout << "�������" << i + 1 << "��������ļ�����:"; 
		cin >> num[i];
		string s;
		int status = 0;
		cout << "�������" << i + 1 << "��������ļ���:"; 
		for(int j = 0; j < num[i]; j++){
			cin >> s;
			// �����ǰ�����Ǳ�Ҫ��
			// ������status
			if(mm.find(s) != mm.end()){
				status |= 1 << mm[s];
			}
		}
		arr[i] = status;
	}
	int dp[m][MAXM];
	for(int i = 0; i < m; i++){
		for(int j = 0; j <= (1 << n); j++){
			dp[i][j] = -1;
		}
	}
	int size = f(arr, 0, 0, dp);
	for(int i = 0, j = 0, s = 0; s != (1 << n) - 1; i++){
		// s ��ʾ��û����
		if(i == m - 1 || dp[i][s] != dp[i + 1][s]){
			// �����ľ�����ѡ����i����
			cout << i << " ";
			j++;
			s |= arr[i];
		}
	}
	return 0;
}
