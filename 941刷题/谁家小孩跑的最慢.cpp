/*
���������Ҹ�������С����һ�죬���ҵľŸ�������һ��������ܣ�
�涨���������С���ܵ�һ��9�֣��ܵ�2��8�֣��������ơ�
����������ҵ��ܷ���ͬ������Щ����û��ͬʱ�����յ�ģ�
Ҳû��һ�ҵ��������������ӻ�����������Ρ���֪���һ��������ҵĺ��ӣ�
��õڶ��������ҵĺ��ӡ��ʻ�����һ������˭�ҵĺ��ӣ�

*/

#include<iostream>
#include<cmath>
#define OK 1
#define NO 0
using namespace std;
int judgement(int i)
{
 int temp;
 int flag=0;
 int mid;
	if(i==1)
	{
		temp=5;
		for(int j=2;j<6;j++)
		{
			 mid=7-j;
			if(fabs(mid-j)==1||mid==temp||j==temp)
			continue;
			else 
			{
			flag=1;
			break;   
			}                                  		
		}
	 } 
  if(i==2)
  {
    temp=6;
  	for(int j=2;j<7;j++)
  	{
  		 mid=6-j;
  		 if(fabs(mid-j)==1||mid==temp||j==temp)
  		 continue;
			else 
			{
			flag=1;
			break;   
			}       
	  }
  }
if(flag==1)
return OK;
else return NO;
}
int main()
{
 
if(judgement(1))
cout<<"L";
else if(judgement(2))
cout<<"W";
else
cout<<"Z";
	return 0;
 } 
