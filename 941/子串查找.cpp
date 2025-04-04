#include <iostream>
using namespace std;
#include <string>

int main()
{
    string A,B;
    cin >> A;
    cin >> B;
    int lena = A.size();
    int lenb = B.size();
    int sum = 0;
    for(int i = 0; i < lena; i++)
    {
        string ans = A.substr(i,lenb);
        if(B.compare(ans) == 0)
            sum++;
    }
    cout << sum << endl;
    return 0;
}
