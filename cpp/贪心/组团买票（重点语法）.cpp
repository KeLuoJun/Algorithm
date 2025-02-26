// ������Ʊ
// ������һ����m����Ŀ�������ĵ�i����Ŀ����������������
// game[i] = { Ki, Bi }��Ki��Biһ��������
// Ki�����ۿ�ϵ����Bi����Ʊ��
// �ٸ����� : Ki = 2, Bi = 10
// ���ֻ��1������Ʊ��������Ʊ�ļ۸�Ϊ : Bi - Ki * 1 = 8
// ������1�����������ĿҪ��8Ԫ
// �����2������Ʊ��������Ʊ�ļ۸�Ϊ : Bi - Ki * 2 = 6
// ������2�����������ĿҪ��6 * 2 = 12Ԫ
// �����5������Ʊ��������Ʊ�ļ۸�Ϊ : Bi - Ki * 5 = 0
// ������5�����������ĿҪ��5 * 0 = 0Ԫ
// ����и�������Ʊ������Ϊ��0Ԫ(��Ϊ����Ŀ����Ǯʵ����̫�ٵ���)
// ���ǿ�����Ϊ�������x������Ʊ��������Ʊ�ļ۸�Ϊ : Bi - Ki * x
// x�������������Ŀ���ܻ����� : max { x * (Bi - Ki * x), 0 }
// ��λһ����n���ˣ�ÿ����������ѡ1����Ŀ�����棬Ҳ���Բ�ѡ�κ���Ŀ
// ����Ա�����������ύѡ��Ȼ������ȥ��������Ĺ���ͳһ��Ǯ��Ʊ
// ����֪���Լ���Ҫ׼������Ǯ���Ϳ���Ӧ�����п��ܵ���������������յ�Ǯ��
// ���������� : 
// 1 <= M��N��Ki��Bi <= 10^5
// ������ʵ�󳧱��ԣ�û�����߲��ԣ���������֤


#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5;

// ��������
// Ϊ����֤
// ÿ�����������п��ܵ�ѡ��
// ʱ�临�Ӷ�O((m+1)��n�η�)
int f(int i, int n, int m, int (*game)[2], int *cnts)
{
	if(i == n){
		int ans = 0;
		for(int j = 0; j < m; j++){
			int k = game[j][0];
			int b = game[j][1];
			int x = cnts[j];
			ans += max((b - k * x) * x, 0);
		}
		return ans;
	}else{
		int ans = f(i + 1, n, m, game, cnts);
		for(int j = 0; j < m; j++){
			cnts[j]++;
			ans = max(ans, f(i + 1, n, m, game, cnts));
			cnts[j]--;
		}
		return ans;
	}
}

int enough1(int n, int m, int (*game)[2])
{
	int *cnts = new int[m];
	// �洢ÿ����Ŀȥ������ 
	memset(cnts, 0, sizeof(cnts));
	return f(0, n, m, game, cnts);
}



// ��ʽ����
// ʱ�临�Ӷ�O(n * logm)
struct Game{
	int ki;
	int bi;
	int people;
	
	Game(int k, int b){
		ki = k;  // �ۿ�ϵ�� 
		bi = b;  // ��Ʊ�۸� 
		people = 0;  // ֮ǰ������ 
	}
	// �������һ�ˣ������Ŀ�õ�����Ǯ
	int earn() const {
		// bi - (people + 1) * ki : ��ǰ���ˣ���Ʊԭ�ۼ����ˣ���ǰ����Ʊ�۸�  
        // people * ki : ��ǰ�˵ĵ�����֮ǰ�������ˣ���Ʊ�۸��ټ�ȥki  
		return bi - (people + 1) * ki - people * ki;
	}
};

struct Compare{
	 // ����ѣ����Է���b.earn() > a.earn()  
	bool operator()(const Game& a, const Game& b){
		return b.earn() > a.earn();
	}
};

int enough2(int n, int m, int (*game)[2])
{
	// �ĸ���Ŀ������һ���������  
    // �����  
	priority_queue<Game, vector<Game>, Compare> heap;
	for(int i = 0; i < m; i++){
		// ��game�е����ݳ�ʼ����Game��������� 
		heap.push(Game(game[i][0], game[i][1]));
	}
	int ans = 0;
	for(int i = 0; i < m; i++){
		// һ�������ˣ������͵���ǰ����Ǯ����Ŀ��ȥ
		if(heap.top().earn() < 0){
			break;
		}
		Game cur = heap.top();
		heap.pop();
		ans += cur.earn();
		cur.people++;
		heap.push(cur);
	}
	return ans;
}


int main()
{
	int n,m;
	srand((unsigned)time(NULL));
	int (*game)[2] = new int[MAXN][2];
	n = rand() % MAXN;
	m = rand() % MAXN; 
//	cin >> n >> m;
//	for(int i = 0; i < m; i++){
//		cin >> game[i][0] >> game[i][1];
//	}
	for(int i = 0; i < m; i++){
		game[i][0] = rand() % MAXN;
		game[i][0] = rand() % MAXN;
	}
	cout << enough1(n, m, game) << endl;
	cout << enough2(n, m, game) << endl;
	return 0;
	
}
