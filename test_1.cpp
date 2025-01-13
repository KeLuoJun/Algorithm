//
// Created by Honor on 2024/6/17.
//

#include "iostream"
#include "cstring"
#include "vector"
//#include "climits"
//#include "algorithm"
using namespace std;
const int MAXN = 52;

typedef struct {
    int data[MAXN];
    int size;
    char sign;
} BigInt;

BigInt a, b;
int ans[MAXN];



bool check(string s)
{
    if((s[0] < '0' || s[0] > '9') && s[0] != '-'){
        return false;
    }

    for(int i = 1; i < s.size(); i++){
        if(s[i] < '0' || s[i] > '9'){
            return false;
        }
    }
    return true;
}



void init(string s, int ty)
{
    memset(ans, 0, MAXN);
    if(ty == 1){
        memset(a.data, 0, MAXN);
        if(s[0] == '-'){
            a.sign = '-';
            s = s.substr(1, s.size());
        }else{
            a.sign = '+';
        }
        a.size = s.size();
        for(int i = 0; i < s.size(); i++){
            a.data[i] = s[s.size() - i - 1] - '0';
        }
    }else{
        memset(b.data, 0, MAXN);
        if(s[0] == '-'){
            b.sign = '-';
            s = s.substr(1, s.size());
        }else{
            b.sign = '+';
        }
        b.size = s.size();
        for(int i = 0; i < s.size(); i++){
            b.data[i] = s[s.size() - i - 1] - '0';
        }
    }
}


string add(BigInt a, BigInt b)
{

    //string subtract(BigInt a, BigInt b);

    int maxl = max(a.size, b.size);
    for(int i = 0; i <= maxl; i++){
        if(a.data[i] + b.data[i] >= 10){
            a.data[i + 1] += (a.data[i] + b.data[i]) / 10;
        }
        ans[i] = (a.data[i] + b.data[i]) % 10;
    }

    while (ans[maxl] == 0 && maxl > 0){
        maxl--;
    }

    string ret = "";

    for(int i = maxl; i >= 0; i--){
        ret += to_string(ans[i]);
    }
    return ret;
}


// 大正数 - 小正数
string subtract(BigInt a, BigInt b)
{

    int maxl = max(a.size, b.size);

    for(int i = 0; i < maxl; i++){
        if(a.data[i] < b.data[i]){
            a.data[i + 1]--;
            b.data[i] += 10;
        }
        ans[i] = a.data[i] - b.data[i];
    }

    while (ans[maxl] == 0 && maxl > 0){
        maxl--;
    }

    if(maxl == 0){
        return "0";
    }
    string ret = "";
    for(int i = maxl; i >= 0; i--){
        ret += to_string(ans[i]);
    }

    return ret;
}


string multip(BigInt a, BigInt b)
{
    int maxl = a.size + b.size;

    for(int i = 0; i < a.size; i++){
        for(int j = 0; j < b.size; j++){
            ans[i + j] = a.data[i] * b.data[j];
            if(ans[i + j] >= 10){
                ans[i + j + 1] += ans[i + j] / 10;
                ans[i + j] %= 10;
            }
        }
    }

    while (ans[maxl] == 0 && maxl > 0){
        maxl--;
    }

    string ret = "";
    for(int i = maxl; i >= 0; i--){
        ret += to_string(ans[i]);
    }
    return ret;
}




void menu()
{
    cout << "===================欢迎使用计算器===================" << endl;
    cout << "|                                                |" << endl;
    cout << "|                  1、更新大整数A                  |" << endl;
    cout << "|                  2、更新大整数B                  |" << endl;
    cout << "|                  3、清屏                        |" << endl;
    cout << "|                  4、大整数 A + B                |" << endl;
    cout << "|                  5、大整数 A - B                |" << endl;
    cout << "|                  6、大整数 A X B                |" << endl;
    cout << "|                  7、大整数 A / B                |" << endl;
    cout << "|                  0、退出程序                    |" << endl;
    cout << "|                                                |" << endl;
    cout << "=================================================" << endl;

}


int main()
{

    int select = -1;
    string A = "0";
    string B = "0";

    menu();

    while (true){
        cout << "请输入您的选择：" << endl;
        cin >> select;

//        // 检查cin是否成功读取
//        if(cin.fail()) {
//            // 清除错误标志
//            cin.clear();
//            // 忽略错误的输入直到下一个'\n'
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "输入有误，请重新输入" << endl;
//            continue; // 跳过剩余的循环体，重新开始下一次循环
//        }

        switch (select) {
            case 1:
                cout << "请输入整数A：";
                while (true){
                    cin >> A;
                    if(check(A)){
                        cout << "更新A的值成功！" << endl;
                        break;
                    }else{
                        cout << "输入有误，请重新输入：" ;
                    }
                }
                init(A, 1);
                system("pause");
                break;
            case 2:
                cout << "请输入整数B：";
                while (true){
                    cin >> B;
                    if(check(B)){
                        cout << "更新B的值成功！" << endl;
                        break;
                    }else{
                        cout << "输入有误，请重新输入：" ;
                    }
                }
                init(B, 2);
                system("pause");
                break;
            case 3:
                system("pause");
                system("cls");
                menu();
                break;
            case 4:
                cout << A << "+" << B << "的结果为：";
                if(a.sign == '-' && b.sign == '+'){
                    cout << subtract(b, a) << endl;
                }else if(a.sign == '+' && b.sign == '-'){
                    cout << subtract(a, b) << endl;
                }else{
                    cout << add(a, b) << endl;
                }

                system("pause");
                break;
            case 5:
                cout << A << "-" << B << "的结果为：";

                if(a.sign == '+' && b.sign == '-'){
                    cout << add(a, b) << endl;
                }else if(a.sign == '-' && b.sign == '+'){
                    cout << "-" << add(a, b) << endl;
                }else if(a.sign == '+' && b.sign == '+'){
                    if(A < B && A.size() == B.size() || A.size() < B.size()){
                        cout << "-" << subtract(b, a) << endl;
                    }else{
                        cout << subtract(a, b) << endl;
                    }
                }else{
                    if(A < B && A.size() == B.size() || A.size() < B.size()){
                        cout << subtract(a, b) << endl;
                    }else{
                        cout << "-" << subtract(b, a) << endl;
                    }
                }

                system("pause");
                break;
            case 6:
                cout << A << "X" << B << "的结果为：";
                //string ret = multip(a, b);
                if((a.sign == '-' && b.sign == '+') || (a.sign == '-' && b.sign == '+')){
                    if(multip(a, b) == "0") {
                        cout << "0" << endl;
                    }
                }else{
                    cout << multip(a, b) << endl;
                }
                system("pause");
                break;

            case 7:
                cout << A << "/" << B << "的结果为：";


                system("pause");
                break;
            case 0:
                int sure;
                cout << "是否确认退出程序：1、是  2、否 : ";
                while (true){
                    cin >> sure;
                    if(sure == 1){
                        cout << "已退出程序！" << endl;
                        system("pause");
                        return 0;
                    } else if(sure == 2){
                        cout << "退出失败，程序仍然运行中" << endl;
                        break;
                    }else{
                        cout << "输入有误，请重新输入:" << endl;
                    }
                }
                break;
            default:
                cout << "输入有误，请重新输入" << endl;
                break;
        }
    }


    return 0;
}
