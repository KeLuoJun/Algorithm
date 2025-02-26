// 单调栈
// 测试连接：https://www.lanqiao.cn/problems/17152/learning/ 

#include <iostream>
using namespace std;
const int N = 3e5 + 10;
typedef long long ll;
ll arr[N];
ll ans[N][2];
ll stack[N];
ll l[N], r[N];
ll n;

// 方式一求单调栈（一次过，但是要有修正阶段） 
long long solve1()
{
    ll r = 0;
    ll cur;
    for(ll i = 0; i < n; i++){
        while(r > 0 && arr[stack[r - 1]] >= arr[i]){
            cur = stack[--r];
            ans[cur][0] = r > 0 ? stack[r - 1] : -1;
            ans[cur][1] = i;
        }
        stack[r++] = i;
    }

    while(r > 0){
        cur = stack[--r];
        ans[cur][0] = r > 0 ? stack[r - 1] : -1;
        ans[cur][1] = -1;
    }

    for(ll i = n - 2; i >= 0; i--){
        if(ans[i][1] != -1 && arr[ans[i][1]] == arr[i]){
            ans[i][1] = ans[ans[i][1]][1];
        }
    }

    ll res = 0;
    for(ll i = 0; i < n; i++){
        if(ans[i][0] == -1) ans[i][0] = 0;
        if(ans[1][1] == -1) ans[i][1] = n - 1;
        ll len = ans[i][1] - ans[i][0] - 1;
        ll num = len * arr[i];
        res = max(res, num);
    }
    return res;
}

// 方式二求单调栈（分左右去求） 
ll solve2()
{
    ll top = 0;
    for(ll i = 0; i < n; i++){
        while(top > 0 && arr[stack[top - 1]] >= arr[i]){
            top--;
        }
        l[i] = top > 0 ? stack[top - 1] : 0;
        stack[top++] = i;
    }
    top = 0;
    for(ll i = n - 1; i >= 0; i--){
        while(top > 0 && arr[stack[top - 1]] >= arr[i]){
            top--;
        }
        r[i] = top > 0 ? stack[top - 1] : n - 1;
        stack[top++] = i;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, (r[i] - l[i] - 1) * arr[i]);
    }
    return ans;
}

int main()
{
  // 请在此输入您的代码
  cin >> n;
  for(int i = 0; i < n; i++){
      cin >> arr[i];
  }
  cout << solve1() << endl;

  return 0;
}
