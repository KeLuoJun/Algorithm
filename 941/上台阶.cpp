#include <iostream>
using namespace std;
 
const int MAXN = 1000; // ����¥�ݽ������ᳬ�����ֵ
int dp[MAXN + 1]; // ��ʼ��Ϊȫ������

// ����a, b, c�ǳ������ڴ����и������ǵľ�����ֵ
int a;
int b;
int c;

void countWays(int n) {
    dp[0] = 1; // �����0����һ�ַ�������ԭ�ز���

    // ����ÿһ��̨��
    for (int i = 1; i <= n; ++i) {
        // ����һ��̨�׹������ֱ�����a��b��c��̨��
        dp[i] = dp[i - a] + dp[i - b] + dp[i - c];
        
        // �����ǰ̨������������a��b��c�������Ӧ��dp[i - x]Ӧ�����ԣ�������0
        if (i - a < 0) dp[i] -= dp[i - a];
        if (i - b < 0) dp[i] -= dp[i - b];
        if (i - c < 0) dp[i] -= dp[i - c];
    }
}

int main() {
    int n;
    std::cin >> n;
    //ÿ�ο����ߵ�̨���� 
	cin >> a >> b >> c;
	
    countWays(n);
    std::cout << "С���ܹ��� " << dp[n] << " �ַ����������ߵ�¥�ݶ��ˡ�\n";

    return 0;
}
