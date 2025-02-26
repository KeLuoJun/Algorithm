#include <iostream>  
#include <string>
using namespace std;  
const int MAXN = 1e5;
char sr[MAXN];
int vis[MAXN] = {0};

//������������������
void permute1(string str, int left, int right)
{
     //��������� left == right ��˵��ȫ�����Ѿ�������ֻ���������
    if (left == right) 
        cout<<str<<endl;
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

// ���ѵķ��� 
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
