//������ 
//ʱ�临�Ӷ� O(N*logN)
 
#include <iostream>
using namespace std;
#define MAXSIZE 1000
int arr[MAXSIZE];
int n;

void swap(int l,int r)
{
	int temp = arr[l];
	arr[l] = arr[r];
	arr[r] = temp;
}

//iλ�õ��������ϵ��������
void heapInsert(int i)
{
	while(arr[i] > arr[(i-1)/2])
	{
		swap(i,(i-1)/2);
		i = (i-1)/2;
	}
} 

//iλ�õ��������µ��������
//��ǰ�ѵĴ�СΪsize
void heapify(int i,int size)
{
	//iΪ��ǰ�ڵ��λ�� 
	int l = i*2+1;
	while(l < size)
	{
		//���Һ����бȽϵó����ĺ��� 
		int best = l+1 < size && arr[l+1] > arr[l] ? l+1 : l;
		//���Һ����е����ֵ���븸�׽ڵ�Ƚ� 
		best = arr[best] > arr[i] ? best : i;
		//���Һ��Ӷ��ȸ��׽ڵ�С 
		if(best == i)
			break;
		swap(best,i);
		i = best;  //���µ�ǰ�ڵ��λ�� 
		l = i*2+1; //���µ�ǰ�ڵ�����ӵ�λ�� 
	}
}


//�Ӷ����׽�������ѣ�O(n * logn)
//���ε����������ֵ���ź���O(n * logn)
//����ʱ�临�Ӷ�O(n * logn)
void heapSort1()
{
	//���������
	for(int i = 0; i < n; i++)
		heapInsert(i);
	int size = n;
	while(size > 1)
	{
		swap(0,--size);
		heapify(0,size);
	}
} 

//�ӵ׵�����������ѣ�O(n)
//���ε����������ֵ���ź���O(n * logn)
//����ʱ�临�Ӷ�ΪO(n * logn)
void heapSort2()
{
	//��ȫ������
	//ÿ�������ĸ��ڵ㶼�ǵ�ǰ�������ֵ 
	for(int i = n-1; i >= 0; i--)
		heapify(i,n);
	int size = n;   //���Ľڵ������������1 
	while(size > 1)
	{
		swap(0,--size);
		heapify(0,size);
	}
 } 


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	// heapSort1();
	heapSort2();
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
