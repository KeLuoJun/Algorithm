#include <stdio.h>
#define N 10
struct student
{
	int num;
	char name[20];
	double score[N];
	double avg;
};
int main()
{
	int n,m;
	printf("��������Ҫͳ�Ƶ�ѧ��������ÿ��ѧ���ĳɼ�������\n");
	scanf("%d %d",&n,&m);
	void input(struct student stu[],int n,int m);
	void print(struct student stu,int m);
	struct student max(struct student stu[],int n);
	struct student stu[n],*p = stu;
	input(p,n,m);
	print(max(p,n),m);
	return 0;
}

void input(struct student stu[],int n,int m)
{
	printf("������%dλѧ����ѧ�š�������%d��ѧ�Ƶĳɼ���\n",n,m);
	for(int i = 0; i < n; i++)
	{
		double sum = 0;
		stu[i].avg = 0;
		scanf("%d %s",&stu[i].num,stu[i].name);
		for(int j = 0; j < m; j++)
		{
			scanf("%lf",&stu[i].score[j]);
			sum += stu[i].score[j];
		}
		stu[i].avg = sum / m;
		
	}
		
	
}
void print(struct student stu,int m)
{
	printf("\n�ɼ���ߵ�ѧ���ǣ�\n");
	printf("ѧ�ţ�%d\n������%s\n",stu.num,stu.name);
	printf("%d�ſεĳɼ��ǣ�",m);
	for(int i = 0; i < m; i++)
		printf("%5.1lf ",stu.score[i]);
	printf("ƽ���ɼ���%6.2lf\n",stu.avg);
}
struct student max(struct student stu[],int n)
{
	int i,m = 0;
	for(i = 0; i < n; i++)
		if(stu[i].avg > stu[m].avg) m = i;
	return stu[m];
}

