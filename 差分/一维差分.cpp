//��ֲ�������������ֵ��Ϊ 0 �������Ͻ��в���
//�ٽ��������ֱ����ԭ�����ϵ�ֵ 

#include <iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int *arr = new int[n+2];
	int *help = new int[n+2]();
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int m;
	cin >> m;   //�ж��ٴ��޸ĵĲ��� 
	int l,r,num;  //�޸Ĳ���  �޸ķ�Χ��a-b ֮���ÿ����+c 
	//�޸Ĳ������ 
	for(int i = 0; i < m; i++)
	{
		cin >> l >> r >> num;
		//�൱�� l--,r--; 
		help[l-1] += num;  
		help[r] -= num;
	}
	for(int i = 1; i < n; i++)
	{
		help[i] += help[i-1];   //ǰ׺�� 
	}
	//��ԭ��ʼ���� 
	for(int i = 0; i < n; i++)
	{
		arr[i] += help[i];
		cout << arr[i] << " ";
	}
	return 0;
		
		
} 
