/*
张王李三家各有三个小孩。一天，三家的九个孩子在一起比赛短跑，
规定不分年龄大小，跑第一得9分，跑第2得8分，依此类推。
比赛结果各家的总分相同，且这些孩子没有同时到达终点的，
也没有一家的两个或三个孩子获得相连的名次。已知获第一名的是李家的孩子，
获得第二的是王家的孩子。问获得最后一名的是谁家的孩子？

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
