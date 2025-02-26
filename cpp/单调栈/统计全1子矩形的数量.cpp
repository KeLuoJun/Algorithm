// ͳ��ȫ1�Ӿ��ε�����
// ����һ�� m * n �ľ��� mat������ֻ��0��1����ֵ
// ���㷵���ж��ٸ� �Ӿ��� ��Ԫ��ȫ������1
// �������� : https://leetcode.cn/problems/count-submatrices-with-all-ones/

#include <iostream>
#include <vector>
using namespace std;
const int N = 151;
vector<int> heights(N, 0);
vector<int> stacks(N, 0);
int r = 0;


// ����
//              1
//              1
//              1         1
//    1         1         1
//    1         1         1
//    1         1         1
//             
//    3  ....   6   ....  8
//   left      cur        i
// ����ͼ������6λ�ô�ջ�е�����6λ�õĸ߶�Ϊ6(����6��1)
// 6λ�õ���ߡ���6λ���������С�ڸ߶�6����3λ��(left)��3λ�õĸ߶���3
// 6λ�õ��ұߡ���6λ���������С�ڸ߶�6����8λ��(i)��8λ�õĸ߶���4
// ��ʱ������ʲô��
// 1) ����4~7��Χ�ϱ����Ը߶�6��Ϊ�ߵľ����м�����
// 2) ����4~7��Χ�ϱ����Ը߶�5��Ϊ�ߵľ����м�����
// Ҳ����˵��<=4�ĸ߶�һ�ɲ���>6�ĸ߶�һ�ɲ���
// ����λ��Ҳ���ջ�ﵯ����������λ�õ�����ʱ��ȥ��
// ��ô��4~7��Χ�ϱ����Ը߶�6��Ϊ�ߵľ����м��������£�
// 4..4  4..5  4..6  4..7
// 5..5  5..6  5..7
// 6..6  6..7
// 7..7
// 10����ʲô��ʽ��
// 4...7��Χ�ĳ���Ϊ4����ô�������� : 4*5/2
// ͬ����4~7��Χ�ϣ������Ը߶�5��Ϊ�ߵľ���Ҳ����ô��
// ����cur��ջ�ﵯ��ʱ���������� : 
// (curλ�õĸ߶�-Max{leftλ�õĸ߶�,iλ�õĸ߶�}) * ((i-left-1)*(i-left)/2)
int countFromBottom(int m)
{
	// height[0...m-1]
    int ans = 0;
    r = 0;
    for(int i = 0; i < m; i++){
        while(r > 0 && heights[stacks[r - 1]] >= heights[i]){
            int cur = stacks[--r];
            if(heights[cur] > heights[i]){
            	// ֻ��height[cur] > height[i]�Ž���
				// �������Ϊheight[cur]==height[i]����curλ�ô�ջ�е���
				// ��ô�����㣡��iλ�õ�����ʱ����˵��
				// ��һ�ڿν��˺ܶ��������ʱ��Ĵ�������"��״ͼ�����ľ���"����
                int left = r == 0 ? -1 : stacks[r - 1];
                int len = i - left - 1;
                int bottom = max(left == -1 ? 0 : heights[left], heights[i]);
                ans += (heights[cur] - bottom) * len * (len + 1) / 2;
            }
        }
        stacks[r++] = i;
    }
    while(r > 0){
        int cur = stacks[--r];
        int left = r == 0 ? -1 : stacks[r - 1];
        int len = m - left - 1;
        int down = left == -1 ? 0 : heights[left];
        ans += (heights[cur] - down) * len * (len + 1) / 2;
    }
    return ans;
}


int numSubmat(vector<vector<int>>& mat) 
{
    int ans = 0;
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[0].size(); j++){
            heights[j] = mat[i][j] == 0 ? 0 : heights[j] + 1;
        }
        ans += countFromBottom(mat[0].size());
    }
    return ans;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> mat(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> mat[i][j];
		}
	}
	int ans = numSubmat(mat);
	cout << ans << endl;
	return 0;
} 
