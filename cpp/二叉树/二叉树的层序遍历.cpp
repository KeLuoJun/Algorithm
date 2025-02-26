#include <iostream>
using namespace std;
#include <list>

//        a
//       / \
//      b   c
//     /\   /\
//    d e  f  g
//      / /   \
//     h i     j


const int MAXN = 2001;
int index = 0;
int l,r;

//��������� 
typedef struct BiTNode
{
	char data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//���������� 
void createBiTree(BiTree &T)
{
	string s = "abd##eh###cfi###g#j##";
	char ch = s[index++];
	if(ch == '#')
		T = NULL;
	else
	{
		T = new BiTNode;
		if(T == NULL) return;
		T->data = ch;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
}

BiTree arr[MAXN];

list< list<char> > levelOrder(BiTree T)
{
	list< list<char> >ans;
	if(T != NULL)
	{
		l = r = 0;
		arr[r++] = T;
		while(l < r)  //�����ﻹ�ж��� 
		{
			int size = r - l;   //Ŀǰ��Ľڵ��� 
			list<char>List;
			for(int i = 0; i < size; i++)
			{
				BiTree cur = arr[l++];   //�����ýڵ� 
				List.push_back(cur->data);  //���ýڵ��data���������� 
				//���ýڵ�����Һ��ӷ��������� 
				if(cur->lchild != NULL)
					arr[r++] = cur->lchild;
				if(cur->rchild != NULL)
					arr[r++] = cur->rchild;
			}
			ans.push_back(List);
		}
	}
	return ans;
}


int main()
{
	BiTree T = NULL;
	createBiTree(T);
	list < list<char> > ans = levelOrder(T);
	
	for(list< list<char> > ::iterator its = ans.begin(); its != ans.end(); its++)
	{
		for(list<char>::iterator it = its->begin(); it != its->end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	return 0;
}
