#include "iostream"
#include<string>
#include <stdio.h>
using namespace std;

int main()
{
    char s[101];
    while(scanf("%s",s)!= EOF)
    {
        int len = 0;
        while(s[len] != '\0') len++;
        for(int i = 0; i < len; i++)
        {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            switch (s[i])
            {
                case 'a':
                case 'b':
                case 'c':
                    s[i] = '2';
                    break;
                case 'd':
                case 'e':
                case 'f':
                    s[i] = '3';
                    break;
                case 'g':
                case 'h':
                case 'i':
                    s[i] = '4';
                    break;
                case 'j':
                case 'k':
                case 'l':
                    s[i] = '5';
                    break;
                case 'm':
                case 'n':
                case 'o':
                    s[i] = '6';
                    break;
                case 'p':
                case 'q':
                case 'r':
                case 's':
                    s[i] = '7';
                    break;
                case 't':
                case 'u':
                case 'v':
                    s[i] = '8';
                    break;
                case 'w':
                case 'x':
                case 'y':
                case 'z':
                    s[i] = '9';
                    break;
            }
        }
        else if(s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
            s[i] = (s[i] - 'a' + 26 + 1)%26 + 'a';
        }
    }
    cout << s << endl;
    }
    
    return 0;
}
