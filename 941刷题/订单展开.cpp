
#include <iostream>
using namespace std;
#include <string>

bool checkNum(char n)
{
    if(n >= '0' && n <= '9')
        return true;
    else
        return false;
}



int main()
{
    char s[100001];
    cin >> s;
    int len = 0;
    for(int i = 0; s[i] != '\0'; i++) len++;
    string ans;
    int count = 0;
    for(int i = 0; i < len; i++)
    {
        if(checkNum(s[i]))
        {
            count *= 10;
            count += (int)(s[i] - '0');
        }
        else
        {
            for(int j = 0; j < count; j++)
            {
                ans += s[i];
            }
            count = 0;
        }
        
    }
    cout << ans << endl;
    return 0;
}
