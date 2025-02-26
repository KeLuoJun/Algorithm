#include <iostream>
using namespace std;
#define MAXSIZE 10

//ѭ�����еĶ��� 
typedef struct
{
	//��ǰ���������Ŀռ� 
	int data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

//ѭ�����еĳ�ʼ��
bool InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return true;
} 

//���ض��е�ǰ�ĳ���
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
 } 
 
//����
bool EnQueue(SqQueue *Q,int e)
{
	if((Q->rear+1)%MAXSIZE == Q->front)  //���������ж� 
		return false;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear+1)%MAXSIZE;
	return true;	
}

//����
bool DeQueue(SqQueue *Q, int *e)
{
	if(Q->rear == Q->front)  //���пյ��ж� 
		return false;
	*e = Q->data[Q->front];
	Q->front = (Q->front+1)%MAXSIZE;
	return true;
}

//��ʾ�����е�����
void ShowQueue(SqQueue Q)
{
	if(Q.front == Q.rear)
	{
		cout << "�ö���Ϊ��" << endl;
		return;	
	}	
	
	while(Q.front != Q.rear)
	{
		cout << Q.data[Q.front] << " ";
		Q.front = (Q.front+1)%MAXSIZE;
	}
}

void test()
{
	SqQueue Q;
	InitQueue(&Q);
	EnQueue(&Q, 1);
	EnQueue(&Q, 2);
	EnQueue(&Q, 3);
	int e;
	DeQueue(&Q,&e);
	cout << "���е�����Ϊ��" << e << endl;
	ShowQueue(Q);
}

int main()
{
	test();
	system("pause");
	return 0;
}
