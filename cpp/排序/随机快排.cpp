//�����������
//ʱ�临�Ӷ� O(N*logN) 

//�Ż��棨�����������⣩
//��֪arr[l....r]��Χ��һ����x���ֵ
//��������  <x�����  ==x���м�  >x���ұ�
//��ȫ�ֱ���first, last ���³�==x��������ұ߽�

#include <iostream>
#include <time.h>
#include<stdlib.h>
using namespace std;
#define MAXSIZE 1000

int arr[MAXSIZE];
int first;  //С��x��Խ����߽� 
int last;   //����x��Խ���ұ߽� 

void swap(int l,int r)
{
	int temp = arr[l];
	arr[l] = arr[r];
	arr[r] = temp;
}

void partition(int l,int r,int x)
{
	first = l;
	last = r;
	int i = l;  //ɨ��Ķ�����
	while(i <= last)
	{
		if(arr[i] == x)
			i++;
		else if(arr[i] < x)
			//����֮������i�ϵ����Ǵ��������߻�����
			//������i��������Ѿ�ɨ�����
			//��˲����ٶԽ���֮��i�ϵ�������ɨ�裬ֱ��ɨ����һλ 
			swap(first++,i++);
		else if(arr[i] > x)
			//����֮��i�ϵ����Ǵ�������ұ߻�����
			//������i���ұ߻�δɨ��� 
			//�����Ҫ�ٶԽ���֮��i�ϵ�������ɨ��
			swap(i,last--);
	} 
} 

void quickSort(int l,int r)
{
	srand((unsigned)time(0));
	if(l >= r)
		return;
	int x = arr[l + (int)rand()%(r-l+1)];
	partition(l,r,x);
	//Ϊ�˷�ֹ�ײ�ĵݹ���̸���ȫ�ֱ���
	//��������ʱ������¼first��last 
	int left = first;
	int right = last;
	quickSort(l,left-1);
	quickSort(right+1,r);
}


int main()
{
	int n;
	cout << "����������ĳ��ȣ�" << endl;
	cin >> n;
	cout << "���������ݵ����ݣ�" << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	quickSort(0,n-1);
	cout << "����������Ϊ��" << endl;
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	system("pause");
	return 0;
} 
