#include <iostream>
using namespace std;

int func(int n,int k)
{
	if(n == 0 || n <= k)
        return 1;
    int a,b;
    a = n/2;
    b = n-a;
    while(b-a < k)
    {
        a--;
        b++;
    }
    if(b-a == k)
    {
        return func(a,k) + func(b,k);
    }
    else
        return 1;
}

int main()
{
    int n,k;
    cin >> n >> k;
    int ans = func(n,k);
    cout << ans << endl;
    return 0;
}
