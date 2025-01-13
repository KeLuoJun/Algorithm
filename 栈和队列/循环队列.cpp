#include <iostream>
using namespace std;
#define MAXSIZE 10

//循环队列的定义 
typedef struct
{
	//提前申请好所需的空间 
	int data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

//循环队列的初始化
bool InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return true;
} 

//返回队列当前的长度
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
 } 
 
//入列
bool EnQueue(SqQueue *Q,int e)
{
	if((Q->rear+1)%MAXSIZE == Q->front)  //队列满的判断 
		return false;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear+1)%MAXSIZE;
	return true;	
}

//出列
bool DeQueue(SqQueue *Q, int *e)
{
	if(Q->rear == Q->front)  //队列空的判断 
		return false;
	*e = Q->data[Q->front];
	Q->front = (Q->front+1)%MAXSIZE;
	return true;
}

//显示队列中的数据
void ShowQueue(SqQueue Q)
{
	if(Q.front == Q.rear)
	{
		cout << "该队列为空" << endl;
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
	cout << "出列的数据为：" << e << endl;
	ShowQueue(Q);
}

int main()
{
	test();
	system("pause");
	return 0;
}
