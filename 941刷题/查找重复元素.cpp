#include <iostream>
using namespace std;
#include <set>


int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    set<int>s1;
    multiset<int>s2;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        s1.insert(num);
    }
    for(int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        s2.insert(num);
    }
    int flag = 1;
    for(set<int>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        int count = s2.count(*it);
        if(count == k)
        {
            cout << *it << " ";
            flag = 0;
        }
        
    }
    if(flag)
    	cout << "-1" << endl;
    return 0;
}
