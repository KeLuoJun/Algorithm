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

typedef struct BiTNode
{
	char data;
	BiTNode *lchild,*rchild;
}BiTNode, *BiTree;


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

int max(int &a,int &b)
{
	return a > b ? a : b;
}


BiTree nq[MAXN];
int iq[MAXN];

int widthOfBinary(BiTree &T)
{
	int ans = 1;
	l = r = 0;
	// nq 和 iq 同步变化
	nq[r] = T;
	iq[r++] = 1;
	while(l < r)
	{
		int size = r-l;
		ans = max(ans,iq[r-1]-iq[l]+1);
		for(int i = 0; i < size; i++)
		{
			BiTree cur = nq[l];
			int id = iq[l++];
			if(cur->lchild != NULL)
			{
				nq[r] = cur->lchild;
				iq[r++] = id*2;
			}
			if(cur->rchild != NULL)
			{
				nq[r] = cur->rchild;
				iq[r++] = id*2+1;
			}
		}
	}
	return ans;
}



int main()
{
	BiTree T = NULL;
	createBiTree(T);
	int ans = widthOfBinary(T);
	cout << ans << endl;
	system("pause");
	return 0;
}
