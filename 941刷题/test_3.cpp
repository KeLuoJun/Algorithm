#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5;
int n;
ll a[N];
ll b[N];
int c[N];
int p = 0;


int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    c[0] = 0;
    for(int i = 1; i < n; i++){
        int j = i - 1;
        int ans = 0;
        if(a[i] > a[j]){
            c[i] = c[j];
        }else{
            while(a[i] < a[j]){
                ans++;
                j--;
            }
            ans += c[j];
            c[i] = ans;
        }
    }
    for(int i = 0; i < n; i++){
        cout << c[i] << endl;
    }
    return 0;
}
