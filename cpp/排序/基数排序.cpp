//��������
//ʱ�临�Ӷ� O(N) 

#include <iostream>
using namespace std;
#define MAXSIZE 1000
 
const int BASE = 10;  //����
int *arr = new int[MAXSIZE];
int n;
int *help = new int[MAXSIZE];  //�������� 
int *cnts = new int[BASE];     //

//����number��BASE�������м�λ
int bits(int num)
{
	int ans = 0;
	while(num)
	{
		ans++;
		num /= BASE;
	}
	return ans;
 } 
 
 
//����������Ĵ���
//arr��Ҫ��֤û�и���

void radixSort(int bits)
{
	//offset Ϊ��ȡ���ֵ���һλ
	//�������ֵ��BASE�����µ�λ������������������������ 
	for(int offset = 1; bits > 0; offset *= BASE,bits--)
	{
		//��cnts���鸴λ
		for(int i = 0; i < BASE; i++)
			cnts[i] = 0; 
		//��ȡ���ֵ�ÿһλ
		for(int i = 0; i < n; i++)
			cnts[(arr[i]/offset)%BASE]++; 
		//cnts ��ǰ׺�� 
		//���ж���λ <= ��ǰλ�ϵ��� 
		for(int i = 1; i < BASE; i++)
			cnts[i] = cnts[i] + cnts[i-1];
		//���ݵ�ǰλ�ϵĵ�����������
		//ע������Ǵ��ҵ��� 
		for(int i = n-1; i >= 0; i--)
			help[--cnts[(arr[i]/offset)%BASE]] = arr[i];
		//������ԭ����
		for(int i = 0; i < n; i++)
			arr[i] = help[i]; 
	}
} 

//���� radixSort�����������������г��ָ���
//���ֽ����������ÿ������ȥ�����е���С���Ǹ��������ڽ��л������� 

void sort()
{
	int min = arr[0];  //��¼�����е���Сֵ 
	int max = 0;       //��¼�����е����ֵ���Ա��������������λ��
	for(int i = 0; i < n; i++)
	{
		if(arr[i] < min)
			min = arr[i];
	} 
	for(int i = 0; i < n; i++)
	{
		//�����е�ÿ��������ȥ�����е���Сֵ���Ͱ�arrת���˷Ǹ�����
		arr[i] -= min;
		//����ת������������ֵ
		if(arr[i] > max)
			max = arr[i]; 
	}
	//���鴦����󣬽��л�������
	radixSort(bits(max));
	//�����꣬��ԭ����
	for(int i = 0; i < n; i++)	
		arr[i] += min; 
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort();
	for(int i = 0; i < n; i++)	
		cout << arr[i] << " ";
	cout << endl;
	system("pause");
	return 0;
 } 
