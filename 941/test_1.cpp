#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

const int MAXN = 52;

class BigInt {
public:
    vector<int> data;
    char sign;

    BigInt(string s = "0") {
        if (s[0] == '-') {
            sign = '-';
            s = s.substr(1);
        } else {
            sign = '+';
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            data.push_back(s[i] - '0');
        }
    }

    string toString() const {
        string ret = (sign == '-' && !isZero()) ? "-" : "";
        for (int i = data.size() - 1; i >= 0; i--) {
            ret += to_string(data[i]);
        }
        return ret;
    }

    bool isZero() const {
        return data.size() == 1 && data[0] == 0;
    }

    // Addition
    BigInt operator+(const BigInt& other) const {
        if (sign == other.sign) {
            BigInt result;
            result.sign = sign;
            result.data = addVectors(data, other.data);
            return result;
        } else {
            if (absGreater(*this, other)) {
                BigInt result;
                result.sign = sign;
                result.data = subtractVectors(data, other.data);
                return result;
            } else {
                BigInt result;
                result.sign = other.sign;
                result.data = subtractVectors(other.data, data);
                return result;
            }
        }
    }

    // Subtraction
    BigInt operator-(const BigInt& other) const {
        if (sign != other.sign) {
            BigInt result;
            result.sign = sign;
            result.data = addVectors(data, other.data);
            return result;
        } else {
            if (absGreater(*this, other)) {
                BigInt result;
                result.sign = sign;
                result.data = subtractVectors(data, other.data);
                return result;
            } else {
                BigInt result;
                result.sign = (sign == '+' ? '-' : '+');
                result.data = subtractVectors(other.data, data);
                return result;
            }
        }
    }

    // Multiplication
    BigInt operator*(const BigInt& other) const {
        BigInt result;
        result.sign = (sign == other.sign) ? '+' : '-';
        result.data = multiplyVectors(data, other.data);
        return result;
    }

    // Division and remainder
    pair<BigInt, BigInt> divmod(const BigInt& other) const {
        //if (other.isZero()) throw overflow_error("Divide by zero");
        BigInt quotient, remainder;
        divideVectors(data, other.data, quotient.data, remainder.data);
        quotient.sign = (sign == other.sign) ? '+' : '-';
        remainder.sign = sign;
        return {quotient, remainder};
    }

private:
    static vector<int> addVectors(const vector<int>& a, const vector<int>& b) {
        vector<int> result(max(a.size(), b.size()) + 1);
        int carry = 0;
        for (size_t i = 0; i < result.size(); i++) {
            int sum = carry;
            if (i < a.size()) sum += a[i];
            if (i < b.size()) sum += b[i];
            result[i] = sum % 10;
            carry = sum / 10;
        }
        removeLeadingZeros(result);
        return result;
    }

    static vector<int> subtractVectors(const vector<int>& a, const vector<int>& b) {
        vector<int> result = a;
        for (size_t i = 0; i < b.size(); i++) {
            result[i] -= b[i];
            if (result[i] < 0) {
                result[i] += 10;
                result[i + 1]--;
            }
        }
        removeLeadingZeros(result);
        return result;
    }

    static vector<int> multiplyVectors(const vector<int>& a, const vector<int>& b) {
        vector<int> result(a.size() + b.size());
        for (size_t i = 0; i < a.size(); i++) {
            for (size_t j = 0; j < b.size(); j++) {
                result[i + j] += a[i] * b[j];
                if (result[i + j] >= 10) {
                    result[i + j + 1] += result[i + j] / 10;
                    result[i + j] %= 10;
                }
            }
        }
        removeLeadingZeros(result);
        return result;
    }

    static void divideVectors(const vector<int>& dividend, const vector<int>& divisor, vector<int>& quotient, vector<int>& remainder) {
        quotient.clear();
        remainder = dividend;
        vector<int> current;
        for (int i = dividend.size() - 1; i >= 0; i--) {
            current.insert(current.begin(), dividend[i]);
            removeLeadingZeros(current);
            int count = 0;
            while (!absLess(current, divisor)) {
                current = subtractVectors(current, divisor);
                count++;
            }
            quotient.insert(quotient.begin(), count);
        }
        removeLeadingZeros(quotient);
        removeLeadingZeros(remainder);
    }

    static bool absGreater(const BigInt& a, const BigInt& b) {
        if (a.data.size() != b.data.size()) return a.data.size() > b.data.size();
        for (int i = a.data.size() - 1; i >= 0; i--) {
            if (a.data[i] != b.data[i]) return a.data[i] > b.data[i];
        }
        return false;
    }

    static bool absLess(const vector<int>& a, const vector<int>& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i] != b[i]) return a[i] < b[i];
        }
        return false;
    }

    static void removeLeadingZeros(vector<int>& v) {
        while (v.size() > 1 && v.back() == 0) v.pop_back();
    }
};

void menu() {
    cout << "===================��ӭʹ�ü�����===================" << endl;
    cout << "|                  1�����´�����A                  |" << endl;
    cout << "|                  2�����´�����B                  |" << endl;
    cout << "|                  3������                         |" << endl;
    cout << "|                  4�������� A + B                 |" << endl;
    cout << "|                  5�������� A - B                 |" << endl;
    cout << "|                  6�������� A X B                 |" << endl;
    cout << "|                  7�������� A / B                 |" << endl;
    cout << "|                  0���˳�����                     |" << endl;
    cout << "====================================================" << endl;
}

bool check(const string& s) {
    if (s.empty()) return false;
    if (s[0] != '-' && (s[0] < '0' || s[0] > '9')) return false;
    for (size_t i = 1; i < s.size(); i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

int main() {
    int select = -1;
    string A = "0", B = "0";
    BigInt a(A), b(B);

    menu();

    while (true) {
        cout << "����������ѡ��" << endl;
        cin >> select;

        switch (select) {
            case 1:
                cout << "����������A��";
                while (true) {
                    cin >> A;
                    if (check(A)) {
                        cout << "����A��ֵ�ɹ���" << endl;
                        a = BigInt(A);
                        break;
                    } else {
                        cout << "�����������������룺";
                    }
                }
                break;
            case 2:
                cout << "����������B��";
                while (true) {
                    cin >> B;
                    if (check(B)) {
                        cout << "����B��ֵ�ɹ���" << endl;
                        b = BigInt(B);
                        break;
                    } else {
                        cout << "�����������������룺";
                    }
                }
                break;
            case 3:
                system("cls");
                menu();
                break;
            case 4:
                cout << "(" << A << ")" << " + " << "(" << B << ")" << "�Ľ��Ϊ��";
                cout << (a + b).toString() << endl;
                break;
            case 5:
                cout << "(" << A << ")" << " - " << "(" << B << ")" << "�Ľ��Ϊ��";
                cout << (a - b).toString() << endl;
                break;
            case 6:
                cout << "(" << A << ")" << " X " << "(" << B << ")" << "�Ľ��Ϊ��";
                cout << (a * b).toString() << endl;
                break;
            case 7:
                if (B == "0" || B == "-0") {
                    cout << "����0������Ϊ����" << endl;
                } else {
                	BigInt quotient, remainder; 
                    tie(quotient, remainder) = a.divmod(b);
                    cout << "(" << A << ")" << " / " << "(" << B << ")" << "�Ľ��Ϊ��";
                    cout << quotient.toString() << " �� " << remainder.toString() << endl;
                }
                break;
            case 0:
                int sure;
                cout << "�Ƿ�ȷ���˳�����1����  2���� : ";
                while (true) {
                    cin >> sure;
                    if (sure == 1) {
                        cout << "���˳�����" << endl;
                        return 0;
                    } else if (sure == 2) {
                        cout << "�˳�ʧ�ܣ�������Ȼ������" << endl;
                        break;
                    } else {
                        cout << "������������������:";
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

