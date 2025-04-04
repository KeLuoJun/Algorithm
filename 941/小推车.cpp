#include <iostream>
using namespace std;
#define MAXSIZE 100000
int arr[5][MAXSIZE];
int help[MAXSIZE];

void merge(int l,int m,int r,int k)
{
    int i = l;
    int a = l;
    int b = m+1;
    while(a <= m && b <= r)
    {
        help[i++] = arr[k][a] <= arr[k][b] ? arr[k][a++] : arr[k][b++];
    }
    while(a <= m)
        help[i++] = arr[k][a++];
    while(b <= r)
        help[i++] = arr[k][b++];
    for(i = l; i <= r; i++)
        arr[k][i] = help[i];
}

void Sort(int l,int r,int k)
{
    if(l == r)
        return;
    int m = (l+r)/2;
    Sort(l,m,k);
    Sort(m+1,r,k);
    merge(l,m,r,k);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < 5; i++)
    {
        int max = 0;
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] > max)
            {
                arr[i][n] = j;
                max = arr[i][j];
            }
        }
    }
    for(int i = 0; i < 5; i++)
    {
        int flag = 0;
        for(int j = arr[i][n]+1; j < n; j++)
        {
            if(arr[i][j] != 0)
                flag = 1;
        }
        if(flag)
            cout << arr[i][arr[i][n]] << endl;
        else
        {
            Sort(0,n-1,i);
            cout << arr[i][n-2] << endl;
        }
    }
    return 0;
}
