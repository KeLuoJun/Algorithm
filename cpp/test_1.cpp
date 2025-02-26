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


// ������ - С����
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
    cout << "===================��ӭʹ�ü�����===================" << endl;
    cout << "|                                                |" << endl;
    cout << "|                  1�����´�����A                  |" << endl;
    cout << "|                  2�����´�����B                  |" << endl;
    cout << "|                  3������                        |" << endl;
    cout << "|                  4�������� A + B                |" << endl;
    cout << "|                  5�������� A - B                |" << endl;
    cout << "|                  6�������� A X B                |" << endl;
    cout << "|                  7�������� A / B                |" << endl;
    cout << "|                  0���˳�����                    |" << endl;
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
        cout << "����������ѡ��" << endl;
        cin >> select;

//        // ���cin�Ƿ�ɹ���ȡ
//        if(cin.fail()) {
//            // ��������־
//            cin.clear();
//            // ���Դ��������ֱ����һ��'\n'
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "������������������" << endl;
//            continue; // ����ʣ���ѭ���壬���¿�ʼ��һ��ѭ��
//        }

        switch (select) {
            case 1:
                cout << "����������A��";
                while (true){
                    cin >> A;
                    if(check(A)){
                        cout << "����A��ֵ�ɹ���" << endl;
                        break;
                    }else{
                        cout << "�����������������룺" ;
                    }
                }
                init(A, 1);
                system("pause");
                break;
            case 2:
                cout << "����������B��";
                while (true){
                    cin >> B;
                    if(check(B)){
                        cout << "����B��ֵ�ɹ���" << endl;
                        break;
                    }else{
                        cout << "�����������������룺" ;
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
                cout << A << "+" << B << "�Ľ��Ϊ��";
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
                cout << A << "-" << B << "�Ľ��Ϊ��";

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
                cout << A << "X" << B << "�Ľ��Ϊ��";
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
                cout << A << "/" << B << "�Ľ��Ϊ��";


                system("pause");
                break;
            case 0:
                int sure;
                cout << "�Ƿ�ȷ���˳�����1����  2���� : ";
                while (true){
                    cin >> sure;
                    if(sure == 1){
                        cout << "���˳�����" << endl;
                        system("pause");
                        return 0;
                    } else if(sure == 2){
                        cout << "�˳�ʧ�ܣ�������Ȼ������" << endl;
                        break;
                    }else{
                        cout << "������������������:" << endl;
                    }
                }
                break;
            default:
                cout << "������������������" << endl;
                break;
        }
    }


    return 0;
}
