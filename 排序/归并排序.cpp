//�鲢����
//ʱ�临�Ӷ� O(N*logN) 

#include <iostream>
using namespace std;
#define MAX 501

int arr[MAX];
int help[MAX];

void merge(int l, int m, int r)
{
	int i = l;
	int a = l;
	int b = m + 1;
	while(a <= m && b <= r)
	{
		help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
	}
	while(a <= m)
		help[i++] = arr[a++];
	while(b <= r)
		help[i++] = arr[b++];
	//��ԭ 
	for(i = l; i <= r; i++)
		arr[i] = help[i];
}

//�ݹ�� 
void mergeSort1(int l, int r)
{
	if(l == r)
		return;
	int m = (l + r) / 2;
	mergeSort1(l,m);
	mergeSort1(m+1,r);
	merge(l,m,r);
}

int min(int a, int b)
{  
	return a > b ? b : a;
}

//�ǵݹ�� 
void mergeSort2(int n)
{
	int l,m,r;
	//step Ϊÿ�λ��ֵĲ���
	//l...m  m+1...r 
	for(int step = 1; step < n; step <<= 1)
	{
		l = 0;
		while(l < n)
		{
			m = l + step - 1;
			if(m+1 >= n)	
				//�Ѿ�û���Ҳ��� 
				break;
			//���Ҳ࣬���Ҳ�����ұ߽磨�����Ҳ಻��step����
			r = min(m+step,n-1);
			merge(l,m,r);
			l = r + 1;
		}
	}
} 

void test()
{
	int num;
	cout << "������Ҫ�������ֵĸ�����";
	cin >> num;
	cout << "������Ҫ��������֣�" ;
	for(int i = 0; i < num; i++)
		cin >> arr[i];
	//mergeSort1(0,num-1);
	mergeSort2(num);
	cout << "�����Ľ����" << endl;
	for(int i = 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
} 

int main()
{
	test();
	system("pause");
	return 0;
}

