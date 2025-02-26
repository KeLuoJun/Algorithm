// ���㲻��ʽ�����ֵ
// ����һ������ points ��һ������ k
// ������ÿ��Ԫ�ض���ʾ��άƽ���ϵĵ�����꣬�����պ����� x ��ֵ��С��������
// Ҳ����˵ points[i] = [xi, yi]
// ������ 1 <= i < j <= points.length ��ǰ���£�xi < xj �ܳ���
// �����ҳ� yi + yj + |xi - xj| �� ���ֵ��
// ���� |xi - xj| <= k �� 1 <= i < j <= points.length
// ��Ŀ�������ݱ�֤���ٴ���һ���ܹ����� |xi - xj| <= k �ĵ㡣
// �������� : https://leetcode.cn/problems/max-value-of-equation/

#include <iostream>
using namespace std;
const int N = 100005;
int n, k;
int points[N][2];
// [��i�ŵ�[x,y]��]
//  h��t
int dq[N][2];
int h, t;

// ��֪���еĵ㶼�Ǹ���xֵ����ģ�
// �κ������㣬���ָ�꣬Ҫ�� : ��x - ǰx <= k
// �������ָ��
int findMaxValueOfEquation()
{
	// ��ʼ���������� 
	h = t = 0;
	int ans = INT_MIN;
	for(int i = 0, x, y; i < n; i++){
		// i�ŵ��Ǵ�ʱ�ĵ㣬��ǰ�ĺ���㣬
		// ��֮ǰ�ĸ����y-xֵ���x�����ֲ��ܳ���k
		x = points[i][0];
		y = points[i][1];
		while(h < t && dq[h][0] + k < x){
			// ��������ͷ���Ŀ����Թ����ˣ�
			// ͷ�����x�뵱ǰ��x�ľ��볬����k
			h++;
		}
		if(h < t){
			ans = max(ans, x + y + dq[h][1] - dq[h][0]);
		}
		// i�ŵ��x��y���ô�β�����뵥������
		// �� -> С
		while(h < t && dq[t - 1][1] - dq[t - 1][0] <= y - x){
			t--;
		}
		dq[t][0] = x;
		dq[t++][1] = y;
	}
	return ans;
}


int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> points[i][0] >> points[i][1];
	}
	int ans = findMaxValueOfEquation();
	cout << ans << endl;
	return 0;
}

