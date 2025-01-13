#include <iostream>
using namespace std;

//�����еĶ��� 
typedef struct QNode
{
	int data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front,rear;
}LinkQueue;

//��ʼ��������
bool InitQueue(LinkQueue *&Q)
{
	Q = new LinkQueue;
	Q->front = new QNode;
	if(Q->front == NULL)
		return false;
	Q->rear = Q->front;
	return true;
} 

//���
//�׽ڵ�Ϊ�� 
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

//����
bool DeQueue(LinkQueue *&Q, int *e)
{
	QueuePtr p;
	if(Q->front == Q->rear)
		return false;
	p = Q->front->next;  //����ɾ���Ķ�ͷ�Ľڵ��ݴ��p 
	*e = p->data;
	Q->front->next = p->next;
	if(Q->rear == p)  //����ͷ���Ƕ�β����ɾ����rearָ��ͷ��� 
		Q->rear = Q->front; 
	delete p;
	return true; 
}

//��ʾ�������е�����
void ShowQueue(LinkQueue *Q)
{
	if(Q->front == Q->rear)
	{
		cout << "�ö���Ϊ��" << endl;
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
