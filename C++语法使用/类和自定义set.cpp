#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int n,q;

struct stock
{
    int p,r;
};

struct compare
{
    bool operator()(const pair<int, stock>&a, const pair<int, stock>&b) const{
        if(a.second.r == b.second.r){
            return a.second.p <= b.second.p;
        }else{
            return a.second.r <= b.second.r;
        }
    }
};


int main()
{
  // 请在此输入您的代码
  stock st[MAXN];
  set<pair<int, stock>, compare> sset;
  set<int>have;
  cin >> n >> q;
  for(int i = 0; i < n; i++){
      cin >> st[i].p >> st[i].r;
      sset.insert(make_pair(i, st[i]));
    }
  while(q--){
      string s;
      cin >> s;
      if(s == "BUY"){
          if(!sset.empty()){
              cout << "SUCCESS " << sset.begin()->first << endl;
              have.insert(sset.begin()->first);
              sset.erase(sset.begin());
          }else{
              cout << "FAIL" << endl;
          }
      }
      if(s == "SELL"){
          int id;
          cin >> id;
          if(have.count(id) > 0){
              cout << "SUCCESS" << endl;
              have.erase(id);
          }else{
              cout << "FAIL" << endl;
          }
      }
      if(s == "UPDATE"){
          int t1,t2,t3;
          cin >> t1 >> t2 >> t3;
          if(sset.count({t1, st[t1]}) > 0){
              sset.erase({t1, st[t1]});
              st[t1].p = t2;
              st[t1].r = t3;
              sset.insert({t1, st[t1]});
          }else{
              st[t1].p = t2;
              st[t1].r = t3;
              sset.insert({t1, st[t1]});
          }
      }
  }
  return 0;
}
