// �����Ӵ�������
// ����һ����������ɵ��ַ���s
// ����s�ж������ַ��������������Ӵ������ظ��� 
// ���е�ÿһ�����ֳ��ֵ�Ƶ�ʶ���ͬ
// �������� : https://leetcode.cn/problems/unique-substrings-with-equal-digit-frequency/

#include <iostream>
#include <string>
#include <string.h>
#include <set>
using namespace std;
const int base = 499;

int equalDigitFrequency(string s)
{
	int n = s.size();
	int cnt[10];   // ��Ƶ�� 
	set<long> hs;
	for(int i = 0; i < n; i++){
		memset(cnt, 0, sizeof(cnt));  // ÿ��cnt��Ҫ���� 
		long hashCode = 0;  // ��ǰ�ַ����Ĺ�ϣֵ
		// curVal ��ǰ�����ַ�ת��Ϊ���ֺ��ֵ
		// maxCnt ��ǰ��������Ƶ�����ֵĴ�Ƶֵ
		// maxCurKinds ӵ���뵱ǰ����Ƶ��ͬ���ַ�����
		// allKinds ��ǰ�ַ������ַ������� 
		int curVal = 0, maxCnt = 0, maxCntKinds = 0, allKinds = 0;
		for(int j = i; j < n; j++){
			curVal = s[i] - '0';
			hashCode = hashCode * base + curVal + 1;
			cnt[curVal]++;
			if(cnt[curVal] == 1){   
				// ��ʾ��ǰ�ַ��ڵ�ǰ�ַ�����ֻ����һ��
				// �Ѹ��ַ������ַ��������� 
				allKinds++;
			}
			if(cnt[curVal] > maxCnt){
				// ��ǰ�ַ��Ĵ�Ƶ����Ŀǰ�ַ����е�����Ƶ
				maxCnt = cnt[curVal]; // �����ַ���������Ƶ 
				maxCntKinds = 1;      // ��ӵ���뵱ǰ����Ƶ��ͬ���ַ��������λ1 
			}else if(cnt[curVal] == maxCnt){
				maxCntKinds++;
			}
			if(maxCntKinds == allKinds){
				// ˵����ǰ�ַ����е�ÿ���ַ����ֵĴ�����ͬ
				//  �Ƕ����Ӵ� 
				hs.insert(hashCode);
			}
		}
	}
	return hs.size();
}


int main()
{
	string s;
	cin >> s;
	int ans = equalDigitFrequency(s);
	cout << ans << endl;
	return 0;
}
