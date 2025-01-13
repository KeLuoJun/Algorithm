#include <iostream>
using namespace std;

//链队列的定义 
typedef struct QNode
{
	int data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front,rear;
}LinkQueue;

//初始化链队列
bool InitQueue(LinkQueue *&Q)
{
	Q = new LinkQueue;
	Q->front = new QNode;
	if(Q->front == NULL)
		return false;
	Q->rear = Q->front;
	return true;
} 

//入队
//首节点为空 
bool EnQueue(LinkQueue *&Q, int e)
{
	QueuePtr s = new QNode;
	if(!s)
		return false;
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
	return true;
}

//出队
bool DeQueue(LinkQueue *&Q, int *e)
{
	QueuePtr p;
	if(Q->front == Q->rear)
		return false;
	p = Q->front->next;  //将欲删除的队头的节点暂存给p 
	*e = p->data;
	Q->front->next = p->next;
	if(Q->rear == p)  //若队头就是队尾，则删除后将rear指向头结点 
		Q->rear = Q->front; 
	delete p;
	return true; 
}

//显示链队列中的数据
void ShowQueue(LinkQueue *Q)
{
	if(Q->front == Q->rear)
	{
		cout << "该队列为空" << endl;
		return;
	}
	else
	{
		Q->front = Q->front->next;
		while(Q->front != Q->rear)
		{
			cout << Q->front->data << " ";
			Q->front = Q->front->next;
		}
		cout << Q->front->data;
		cout << endl;
	}
 } 

void test()
{
	LinkQueue *Q;
	InitQueue(Q);
	EnQueue(Q,1);
	EnQueue(Q,2);
	EnQueue(Q,3);
	ShowQueue(Q);
}
 
int main()
{
	test();
	system("pause");
	return 0;
}
