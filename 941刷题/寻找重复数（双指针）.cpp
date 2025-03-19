/*����һ������ n + 1 ������������ nums ��
�����ֶ��� [1��n] ��Χ�� (���� 1 �� n)��֪���ٴ���һ���ظ���������
���� numsֻ�� һ���ظ������� ��
���� ����ظ�����
����ƵĽ���������벻�޸����� nums ��ֻ�ó����� 0(1) ����ռ䡣
*/

#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[100];
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);    //ֻ������1--(n-1) �ϵ�����
		
	int slow = a[0];
	int fast = a[a[0]];
	while(slow != fast)
	{
		fast = a[a[fast]];
		slow = a[slow];
	} 
	fast = 0;
	while(fast != slow)
	{
		fast = a[fast];
		slow = a[slow];
	}
	printf("%d",slow);
	return 0;
}
