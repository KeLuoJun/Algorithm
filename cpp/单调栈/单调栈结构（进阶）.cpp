// ����ջ��ÿ��λ���������࣬�뵱ǰλ���������ֵ�ϸ�С�ڵ�λ��
// ����һ�����ܺ��� �ظ� ֵ������ arr
// �ҵ�ÿһ�� i λ����ߺ��ұ��� i λ�������ֵ�� arr[i] С��λ��
// ��������λ����Ӧ����Ϣ��
// ����������
// ��һ������һ������ n����ʾ���� arr �ĳ��ȡ�
// ����һ������ n �����֣���ʾ�����ֵ
// ���������
// ���n�У�ÿ���������� L �� R����������ڣ���ֵΪ -1���±�� 0 ��ʼ��
// �������� : https://www.nowcoder.com/practice/2a2c00e7a88a498693568cef63a4b7bb
// ��ͨ�ã� 


// ������Ҵ���  ջ��Сѹ��
// �������С��  ջ����ѹС
// ����ջ��Ҫ��Ҫ�ϸ��ѹС��Сѹ�󣩣�����Ŀ��� 
// ��ȵ�ʱ��Ҳ��������ֻ�����һ����ȵ�ֵ������ʱ�������ǶԵ�
// ����Ҫ�������� 


#include <iostream>
using namespace std;
const int MAXN = 1000000;
int (*ans)[2] = new int[MAXN][2];
int *stack = new int[MAXN];

void compute(int *arr,int n)
{
	int r = 0;
	int cur;
	//�����׶� 
	for(int i = 0; i < n; i++)
	{
		while(r > 0 && arr[i] <= arr[stack[r - 1]])
		{
			// cur��ǰ������λ�ã���������С
			cur = stack[--r];
			ans[cur][0] = r > 0 ? stack[r - 1] : -1;
			ans[cur][1] = i;
		}
		stack[r++] = i;
	}
	
	//����׶� 
	while(r > 0)
	{
		cur = stack[--r];
		ans[cur][0] = r > 0 ? stack[r - 1] : -1;
		ans[cur][1] = -1;
	}
	
	//�����׶� 
	// ���Ĵ𰸲���Ҫ����һ������ȷ�ģ�ֻ���Ҳ����Ҫ����
	// ��Ϊ��඼����ջ�еõ��Ĵ𰸣���ջ���ϸ�Ĵ�ѹС�� 
	// ��������������n-1λ�õ��Ҳ��һ����-1������Ҫ����
	// ������ a[i],a[j]������ͬ����i��j֮ǰ�����ֱش���a[i] 
	for(int i = n - 2; i >= 0; i--)
	{
		if(ans[i][1] != -1 && arr[ans[i][1]] == arr[i])
			ans[i][1] = ans[ans[i][1]][1];
	}
}

//// �ڶ��ַ�ʽ�󵥵�ջ
//// ���� l[]��ʾ���ұ��Լ�С�����λ�� 
////      r[]��ʾ������Լ�С�����λ��  
//typedef long long ll;
//ll solve()
//{
//    ll top = 0;
//    for(ll i = 0; i < n; i++){
//        while(top > 0 && arr[stack[top - 1]] >= arr[i]){
//            top--;
//        }
//        l[i] = top > 0 ? stack[top - 1] : 0;
//        stack[top++] = i;
//    }
//    top = 0;
//    for(ll i = n - 1; i >= 0; i--){
//        while(top > 0 && arr[stack[top - 1]] >= arr[i]){
//            top--;
//        }
//        r[i] = top > 0 ? stack[top - 1] : n - 1;
//        stack[top++] = i;
//    }
//
//    ll ans = 0;
//    for(int i = 0; i < n; i++){
//        ans = max(ans, (r[i] - l[i] - 1) * arr[i]);
//    }
//    return ans;
//}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++)	
		cin >> arr[i];
	compute(arr, n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= 1; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	delete[] arr;
	return 0;
 } 
