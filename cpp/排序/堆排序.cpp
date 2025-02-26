//堆排序 
//时间复杂度 O(N*logN)
 
#include <iostream>
using namespace std;
#define MAXSIZE 1000
int arr[MAXSIZE];
int n;

void swap(int l,int r)
{
	int temp = arr[l];
	arr[l] = arr[r];
	arr[r] = temp;
}

//i位置的数，向上调整大根堆
void heapInsert(int i)
{
	while(arr[i] > arr[(i-1)/2])
	{
		swap(i,(i-1)/2);
		i = (i-1)/2;
	}
} 

//i位置的数，向下调整大根堆
//当前堆的大小为size
void heapify(int i,int size)
{
	//i为当前节点的位置 
	int l = i*2+1;
	while(l < size)
	{
		//左右孩子中比较得出最大的孩子 
		int best = l+1 < size && arr[l+1] > arr[l] ? l+1 : l;
		//左右孩子中的最大值再与父亲节点比较 
		best = arr[best] > arr[i] ? best : i;
		//左右孩子都比父亲节点小 
		if(best == i)
			break;
		swap(best,i);
		i = best;  //更新当前节点的位置 
		l = i*2+1; //更新当前节点的左孩子的位置 
	}
}


//从顶到底建立大根堆，O(n * logn)
//依次弹出堆内最大值并排好序，O(n * logn)
//整体时间复杂度O(n * logn)
void heapSort1()
{
	//建立大根堆
	for(int i = 0; i < n; i++)
		heapInsert(i);
	int size = n;
	while(size > 1)
	{
		swap(0,--size);
		heapify(0,size);
	}
} 

//从底到顶建立大根堆，O(n)
//依次弹出堆内最大值并排好序，O(n * logn)
//整体时间复杂度为O(n * logn)
void heapSort2()
{
	//完全二叉树
	//每个子树的根节点都是当前树的最大值 
	for(int i = n-1; i >= 0; i--)
		heapify(i,n);
	int size = n;   //树的节点数，弹出则减1 
	while(size > 1)
	{
		swap(0,--size);
		heapify(0,size);
	}
 } 


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	// heapSort1();
	heapSort2();
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
