#include <iostream>
using namespace std;
#include <string>

int main()
{
	string s;
	cin >> s;
	int last[26] = {-1};  //�洢�����ַ����³��ֵ�λ�� 
	int ans = 0;
	for(int l = 0,r = 0; r < s.size(); r++)
	{
		//�ж��Ӵ��е��ַ��Ƿ��뽫Ҫ�����r�����ַ��ظ�
		//���ظ���l���µ��Ӵ����ַ���r���ַ��ظ�����һ��λ�� 
		l = max(l,last[s[r] - 'a'] + 1);
		ans = ans > r - l + 1 ? ans : r - l + 1;
		last[s[r] - 'a'] = r;  //����λ�� 
	}
	cout << ans << endl;
	return 0;
}
