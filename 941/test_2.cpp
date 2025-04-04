// h�� 

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

// ȫ����
void permute1(string str, int left, int right)
{
     //��������� left == right ��˵��ȫ�����Ѿ�������ֻ���������
    if (left == right) 
        cout<<str<<endl;
        if(check(str)){
            ans++;
        }
    else {
        // �ݹ����������ʣ��Ԫ�ص�����
        for (int i = left; i <= right; i++) 
        {
            // ����ǰԪ�����һ��Ԫ�ؽ���
            // ���ֵ�һ��Ԫ�ع̶�����������Ԫ�ص�����
            swap(str[left], str[i]);
            // �ݹ����
            permute1(str, left+1, right);
            //���л���
            swap(str[left], str[i]);
        }
    }
}

// ������
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
