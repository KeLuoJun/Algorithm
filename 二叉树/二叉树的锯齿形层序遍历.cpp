#include <iostream>
using namespace std;
#include <list>
const int MAXN = 2001;
int index = 0;
int l,r;

//        a
//       / \
//      b   c
//     /\   /\
//    d e  f  g
//      / /   \
//     h i     j




typedef struct BiTNode
{
	char data;
	BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

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

list <list<char> > zigagLevelOrder(BiTree &T)
{
	list < list<char> >ans;
	if(T != NULL)
	{
		l = r = 0;
		arr[r++] = T;
		// false 代表从左往右
		// true  代表从右往左
		bool reverse = false;
		while(l < r)
		{
			int size = r - l;
			list<char>List;
			// j 决定 i 是+1还是-1 
			for(int i = reverse ? r-1 : l, k = 0, j = reverse ? -1 : 1; k < size; k++,i+=j)
			{
				List.push_back(arr[i]->data);
			}
			
			for(int i = 0; i < size; i++)
			{
				BiTree cur = arr[l++];
				if(cur->lchild != NULL)
					arr[r++] = cur->lchild;
				if(cur->rchild != NULL)
					arr[r++] = cur->rchild;
			}
			ans.push_back(List);
			reverse = !reverse;
		}
	}
	return ans;
}


int main()
{
	BiTree T = NULL;
	createBiTree(T);
	list< list<char> >ans = zigagLevelOrder(T);
	for(list< list<char> >::iterator its = ans.begin(); its != ans.end(); its++)
	{
		for(list<char>::iterator it = its->begin(); it != its->end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
