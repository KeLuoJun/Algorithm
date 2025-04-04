#include "iostream"
#include "string"
using namespace std;
#include <iomanip>
#include "stdlib.h"
using std::setw;
const int MAX = 1000;
void Menu()
{
    cout << "\t\t\t\t\t--------- ѧ���ɼ�����ϵͳ ----------" << endl;
    cout << "\t\t\t\t\t1������ѧ����¼" << endl;
    cout << "\t\t\t\t\t2���޸�ѧ����¼" << endl;
    cout << "\t\t\t\t\t3��ɾ��ѧ����¼" << endl;
    cout << "\t\t\t\t\t4������ѧ����¼" << endl;
    cout << "\t\t\t\t\t5����ʾ���м�¼" << endl;
    cout << "\t\t\t\t\t6����ѯѧ����¼" << endl;
    cout << "\t\t\t\t\t7����ƽ���ɼ�����" << endl;
    cout << "\t\t\t\t\t8���������Ŀ������ѧ��" << endl;
    cout << "\t\t\t\t\t9���������Ŀ��߷�" << endl;
    cout << "\t\t\t\t\t0���˳�" << endl;
}

//����ѧ���ṹ��
struct Student
{
    string ID; //ѧ��
    string Name;  //����
    float Mark1;  //���ĳɼ�
    float Mark2;  //��ѧ�ɼ�
    float Mark3;  //Ӣ��ɼ�
    float Mark4;  //������ɼ�
    float All;    //�ܷ�
    float Average;//ƽ���ɼ�
};
//����ѧ������
struct Student stu[MAX];
int num = 0;   //������


void Copy(struct Student *arr)
{

}

//ͨ������������ѧ��
int SearchByName(string name)
{
    for(int i = 0; i < num; i++)
    {
        if(stu[i].Name == name)
            return i;
    }
    return -1;
}

//ͨ��ѧ��������ѧ��
int SearchByID(string id)
{
    for(int i = 0; i < num; i++)
    {
        if(stu[i].ID == id)
            return i;
    }
    return -1;
}

//��������Ҫ�޸�ѧ����¼
void ModifyInput(int ans)
{
    cout << "�������޸ĺ��������";
    cin >> stu[ans].Name;
    cout << "�������޸ĺ��ѧ�ţ�";
    cin >> stu[ans].ID;
    cout << "�������޸ĺ�����ĳɼ���";
    cin >> stu[ans].Mark1;
    cout << "�������޸ĺ����ѧ�ɼ���";
    cin >> stu[ans].Mark2;
    cout << "�������޸ĺ��Ӣ��ɼ���";
    cin >> stu[ans].Mark3;
    cout << "�������޸ĺ�ļ�����ɼ���";
    cin >> stu[ans].Mark4;
    stu[ans].All = stu[ans].Mark1 + stu[ans].Mark2 + stu[ans].Mark3 + stu[ans].Mark4;
    stu[ans].Average = stu[ans].All / 4;
}
//1������ѧ����¼
void AddRecord()
{
    int flag = 1;
    while (flag)
    {
        cout << "������������" ;
        cin >> stu[num].Name ;
        cout << "������ѧ�ţ�" ;
        cin >> stu[num].ID ;
        cout << "���������ĳɼ���" ;
        cin >> stu[num].Mark1 ;
        cout << "��������ѧ�ɼ���" ;
        cin >> stu[num].Mark2 ;
        cout << "������Ӣ��ɼ���" ;
        cin >> stu[num].Mark3 ;
        cout << "�����������ɼ���" ;
        cin >> stu[num].Mark4 ;
        stu[num].All = stu[num].Mark1 + stu[num].Mark2 + stu[num].Mark3 + stu[num].Mark4;
        stu[num].Average = stu[num].All / 4;
        num++;
        cout << "�Ƿ������ӣ�0--�˳�  1--��������";
        cin >> flag;
    }
}

//2���޸�ѧ����¼
void ModifyRecord() {
    int sign;
    cout << "ͨ���������ң�����1������ͨ��ѧ�Ų��ң�����2����";
    while (true) {
        cin >> sign;
        if (sign == 1 || sign == 0)
            break;
        else
            cout << "�����ʽ�������������룺" << endl;
    }
    int ans;
    if (sign) {
        string name;
        cout << "������Ҫ�޸ĵ�ѧ����������";
        cin >> name;
        ans = SearchByName(name);
    } else
    {
        string id;
        cout << "������Ҫ�޸ĵ�ѧ����ѧ�ţ�" ;
        cin >> id;
        ans = SearchByID(id);
    }
    if (ans >= 0) {
        ModifyInput(ans);
    } else
        cout << "���޴���" << endl;
}
//3��ɾ��ѧ����¼
void DeleteRecord()
{
    int sign;
    cout << "ͨ���������ң�����1������ͨ��ѧ�Ų��ң�����0����";
    while (true) {
        cin >> sign;
        if (sign == 1 || sign == 0)
            break;
        else
            cout << "�����ʽ��������������" << endl;
    }
    int ans;
    if (sign) {
        string name;
        cout << "������Ҫɾ����ѧ����������";
        cin >> name;
        ans = SearchByName(name);
    } else
    {
        string id;
        cout << "������Ҫɾ����ѧ����ѧ�ţ�" ;
        cin >> id;
        ans = SearchByID(id);
    }
    if(ans >= 0)
    {
        char c;
        cout << "�Ƿ�ȷ��ɾ������y/n��";
        cin >> c;
        if(c == 'y')
        {
            num--;
            for(int i = ans; i < num; i++)
            {
                stu[i] = stu[i+1];
            }
            cout << "ɾ���ɹ���" << endl;
        } else if(c == 'n')
            cout << "�˳�ɾ��" << endl;
    } else
        cout << "���޴���" << endl;
}

//4������ѧ����¼
void InsectRecord()
{
    int a;
    cout << "������Ҫ�����λ�ã�" ;
    cin >> a;
    a--;
    if(a < 0 || a > num)
        cout << "����λ�ô���" << endl;
    else
    {
        for(int i = num; i > a; i--)
            stu[i] = stu[i-1];
        cout << "������������" ;
        cin >> stu[a].Name ;
        cout << "������ѧ�ţ�" ;
        cin >> stu[a].ID ;
        cout << "���������ĳɼ���" ;
        cin >> stu[a].Mark1 ;
        cout << "��������ѧ�ɼ���" ;
        cin >> stu[a].Mark2 ;
        cout << "������Ӣ��ɼ���" ;
        cin >> stu[a].Mark3 ;
        cout << "�����������ɼ���" ;
        cin >> stu[a].Mark4 ;
        stu[a].All = stu[a].Mark1 + stu[a].Mark2 + stu[a].Mark3 + stu[a].Mark4;
        stu[a].Average = stu[a].All / 4;
        num++;
    }
}

//5����ʾ���м�¼
void ShowRecord()
{
    for(int i = 0; i < num; i++)
    {
        cout << "��" << i+1 << "λ" << "ѧ��  " ;
        cout << "������" << std::left << setw(6) << stu[i].Name;
        cout << "ѧ�ţ�" << setw(10) << stu[i].ID;
        cout << "���ĳɼ���" << setw(5) << stu[i].Mark1;
        cout << "��ѧ�ɼ���" << setw(5) << stu[i].Mark2;
        cout << "Ӣ��ɼ���" << setw(5) << stu[i].Mark3;
        cout << "������ɼ���" << setw(5) << stu[i].Mark4;
        cout << "�ܷ֣�" << setw(5) << stu[i].All;
        cout << "ƽ���֣�" << setw(5) << stu[i].Average;
        cout << endl;
    }
}

//6����ѯѧ����¼
void CheckRecord()
{
    string name;
    cout << "������Ҫ��ѯ��ѧ����������" ;
    cin >> name;
    int index = SearchByName(name);
    if(index == -1)
        cout << "���޴���" << endl;
    else
    {
        cout << "��" << index+1 << "λ" << "ѧ��  " ;
        cout << "������" << std::left << setw(6) << stu[index].Name;
        cout << "ѧ�ţ�" << setw(6) << stu[index].ID;
        cout << "���ĳɼ���" << setw(5) << stu[index].Mark1;
        cout << "��ѧ�ɼ���" << setw(5) << stu[index].Mark2;
        cout << "Ӣ��ɼ���" << setw(5) << stu[index].Mark3;
        cout << "������ɼ���" << setw(5) << stu[index].Mark4;
        cout << "�ܷ֣�" << setw(5) << stu[index].All;
        cout << "ƽ���֣�" << setw(5) << stu[index].Average;
        cout << endl;
    }

}

//7����ƽ���ɼ�����
void SortAverage()
{
    Student temp;
    for(int i = 0; i < num-1; i++)
    {
        for(int j = 0; j < num-i-1; j++)
        {
            if(stu[j].All > stu[j+1].All)
            {
                temp = stu[j+1];
                stu[j+1] = stu[j];
                stu[j] = temp;
            }
        }
    }
    ShowRecord();
}

//8���������Ŀ�������ѧ��
void CheckLow()
{
    cout << "���ĳɼ��������ѧ����";
    for(int i = 0; i < num; i++)
    {
        if(stu[i].Mark1 < 60)
            cout << setw(6) << stu[i].Name;
        if(i % 5 == 0)
            cout << endl;
    }
    cout << endl;
    cout << "��ѧ�ɼ��������ѧ����";
    for(int i = 0; i < num; i++)
    {
        if(stu[i].Mark2 < 60)
            cout << setw(6) << stu[i].Name;
        if(i % 5 == 0)
            cout << endl;
    }
    cout << endl;
    cout << "Ӣ��ɼ��������ѧ����";
    for(int i = 0; i < num; i++)
    {
        if(stu[i].Mark3 < 60)
            cout << setw(6) << stu[i].Name;
        if(i % 5 == 0)
            cout << endl;
    }
    cout << endl;
    cout << "������ɼ��������ѧ����";
    for(int i = 0; i < num; i++)
    {
        if(stu[i].Mark4 < 60)
            cout << setw(6) << stu[i].Name;
        if(i % 5 == 0)
            cout << endl;
    }
    cout << endl;
}

//9���������Ŀ����߷�
void InputTop()
{
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;
    int max4 = 0;
    for(int i = 1; i < num; i++)
    {
        if(stu[i].Mark1 > stu[max1].Mark1)
            max1 = i;
        if(stu[i].Mark2 > stu[max2].Mark2)
            max2 = i;
        if(stu[i].Mark3 > stu[max3].Mark3)
            max3 = i;
        if(stu[i].Mark4 > stu[max4].Mark4)
            max4 = i;
    }
    float g1 = stu[max1].Mark1;
    float g2 = stu[max2].Mark2;
    float g3 = stu[max3].Mark3;
    float g4 = stu[max4].Mark4;
    cout << "���ĳɼ���߷֣�";
    for(int i = 0; i < num; i++)
        if(stu[i].Mark1 == g1)
            cout << setw(10) << stu[i].Name;
    cout << endl;
    cout << "��ѧ�ɼ���߷֣�";
    for(int i = 0; i < num; i++)
        if(stu[i].Mark2 == g2)
            cout << setw(10) << stu[i].Name;
    cout << endl;
    cout << "Ӣ��ɼ���߷֣�";
    for(int i = 0; i < num; i++)
        if(stu[i].Mark3 == g3)
            cout << setw(10) << stu[i].Name;
    cout << endl;
    cout << "������ɼ���߷֣�";
    for(int i = 0; i < num; i++)
        if(stu[i].Mark4 == g4)
            cout << setw(10) << stu[i].Name;
    cout << endl;
}

int main()
{
    int t;
    while (true)
    {
        Menu();
        cin >> t;
        switch (t) {
            case 1:
                AddRecord();
                system("pause");
                system("cls");
                break;
            case 2:
                ModifyRecord();
                system("pause");
                system("cls");
                break;
            case 3:
                DeleteRecord();
                system("pause");
                system("cls");
                break;
            case 4:
                InsectRecord();
                system("pause");
                system("cls");
                break;
            case 5:
                ShowRecord();
                system("pause");
                system("cls");
                break;
            case 6:
                CheckRecord();
                system("pause");
                system("cls");
                break;
            case 7:
                SortAverage();
                system("pause");
                system("cls");
                break;
            case 8:
                CheckLow();
                system("pause");
                system("cls");
                break;
            case 9:
                InputTop();
                system("pause");
                system("cls");
                break;
            case 0:
                return 0;
            default:
                break;
        }
    }
}
