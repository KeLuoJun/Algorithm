// DÃ‚ 

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 1;
int n,q;
int a[N];

// 1 1 2 4 5
int main()
{
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + 1);
    int k;
    while(q--){
        cin >> k;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int cur = 1;
            if(a[i] == cur){
                cur++;
                for(int j = i + 1; j < n; j++){
                	if(cur - 1 == k){
                		ans++;
                		break;
					}
                    if(a[j] == cur){
                        cur++;
                    }
                }
            }
//            if(cur - 1 == k){
//                ans++;
//            }
        }
        cout << ans << endl;
    }
    return 0;
}
