// ���ΪN���������
// ����һ���� �ǵݼ�˳�� ���е��������� digits
// ��֪digitsһ��������'0'�����ܰ���'1' ~ '9'�������ظ��ַ�
// �������������� digits[i] ��д������
// ���磬��� digits = ['1','3','5']
// ���ǿ���д���֣��� '13', '551', �� '1351315'
// ���� �������ɵ�С�ڻ���ڸ������� n ���������ĸ���
// �������� : https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/

#include <iostream>
using namespace std;
#include <iostream>
int n;
int dlen;

// offset�Ǹ�����������ȫ��len������ֻ��Ϊ�˷�����ȡnum��ĳһλ���֣����ǹؼ�����
// ��ʣ��lenλû�о���
// ���֮ǰ��λ�Ѿ�ȷ����numС����ôfree == 1����ʾ���µ����ֿ�������ѡ��
// ���֮ǰ��λ��numһ������ôfree == 0����ʾ���µ����ֲ��ܴ���num��ǰλ������
// ���֮ǰ��λû��ʹ�ù����֣�fix == 0
// ���֮ǰ��λ�Ѿ�ʹ�ù����֣�fix == 1
// ��������<=num�Ŀ������ж�����
int f1(int *digits, int n, int offset, int len, int free, int fix)
{
	if(len == 0)
	// ��fix==0��˵��֮ǰһ��λ��Ҳû��ѡ�� 
		return fix == 1 ? 1 : 0;
	int ans = 0;
	// num�ڵ�ǰλ������
	int cur = (n / offset) % 10;
	if(fix == 0){
		// ֮ǰ����û��ѡ�������
		// ��ǰ��Ȼ���Բ�Ҫ�κ����֣��ۼӺ����Ŀ�����
		ans += f1(digits, n, offset / 10, len - 1, 1, 0);
	}
	if(free == 0){
		// ��������ѡ������
		for(int i = 0; i < dlen; i++){
			if(digits[i] < cur){
				ans += f1(digits, n, offset / 10, len - 1, 1, 1);
			}else if(digits[i] == cur){
				ans += f1(digits, n, offset / 10, len - 1, 0, 1);
			}else
				break;
		}
	}else{
		// ��������ѡ������
		ans += dlen * f1(digits, n, offset / 10, len - 1, 1, 1);
	}
	return ans;
}


int compute1(string nums, int n)
{
	int tmp = n / 10;
	int len = 1;
	int offset = 1;
	while(tmp > 0){
		tmp /= 10;
		len++;
		offset *= 10;
	}
	int m = nums.size();
	dlen = m;
	int *digits = new int[m + 1];
	for(int i = 0; i < m; i++){
		digits[i] = nums[i];
	return f1(digits, n, offset, len, 0, 0);
	}
}


// offset�Ǹ�����������lenȷ����������ȡnum��ĳһλ����
// ��ʣ��lenλû�о�����֮ǰ��λ��numһ��
// ��������<=num�Ŀ������ж�����
int f2(int *digits, int *cnt, int n, int offset, int len)
{
	if(len == 0)
	// ��Ϊ�´κ���ͳ�Ƶķ�Χ�ڣ�ǰһ��������ѡ 
		return 1;
	int ans = 0;
	int cur = (n / offset) % 10;
	for(int i = 0; i < dlen; i++){
		if(digits[i] < cur){
			ans += cnt[len - 1];
		}
		else if(digits[i] == cur){
			ans += f2(digits, cnt, n, offset / 10, len - 1);
		}
		else	
			break;
	}
	return ans;
}


int compute2(string nums, int n)
{
	int m = nums.size();
	int *digits = new int[m];
	for(int i = 0; i < m; i++)	
		digits[i] = nums[i];
	int len = 1;
	int offset = 1;
	int tmp = n / 10;
	while(tmp > 0){
		len++;
		offset *= 10;
		tmp /= 10;
	}
	int *cnt = new int[len];
	cnt[0] = 1;
	int ans = 0;
	// cnt[i] : ��֪ǰ׺��numС��ʣ��iλû��ȷ��������ǰ׺ȷ��������£�һ���ж�������������
	// cnt[0] = 1����ʾ�����Ѿ�û���ˣ�ǰ׺��״������ȷ������ô����1��
	// cnt[1] = m
	// cnt[2] = m * m
	// cnt[3] = m * m * m
	// ...
	for(int i = m, k = 1; k < len; k++, i *= m){
		cnt[k] = i;
		ans += i;
	}
	return ans + f2(digits, cnt, n, offset, len);
} 


int main()
{
	string nums;
	cin >> n;
	cin >> nums;
	cout << compute1(nums, n) << endl;
	cout << compute2(nums, n) << endl; 
	return 0;
}
