// »¬¶¯´°¿Ú 

#include <iostream>
using namespace std;
#include <algorithm>
const int MAXN = 1e5 + 1;
int *arr = new int[MAXN];

int main()
{
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)  
        cin >> arr[i];
    int l = 0, r = 0;
    int ans = 0;
    while(r < n)
    {
        if(arr[r] - arr[l] <= k){
            r++;
        }
        else{
            ans = max(ans, r - l);
            l++;
        }
    }
    ans = max(ans, r - l);
    cout << ans << endl;
    return 0;
}
