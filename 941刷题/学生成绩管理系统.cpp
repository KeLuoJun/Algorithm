#include "iostream"
#include "string"
using namespace std;
#include <iomanip>
#include "stdlib.h"
using std::setw;
const int MAX = 1000;
void Menu()
{
    cout << "\t\t\t\t\t--------- 学生成绩管理系统 ----------" << endl;
    cout << "\t\t\t\t\t1、增加学生记录" << endl;
    cout << "\t\t\t\t\t2、修改学生记录" << endl;
    cout << "\t\t\t\t\t3、删除学生记录" << endl;
    cout << "\t\t\t\t\t4、插入学生记录" << endl;
    cout << "\t\t\t\t\t5、显示所有记录" << endl;
    cout << "\t\t\t\t\t6、查询学生记录" << endl;
    cout << "\t\t\t\t\t7、按平均成绩排序" << endl;
    cout << "\t\t\t\t\t8、输出各科目不及格学生" << endl;
    cout << "\t\t\t\t\t9、输出各科目最高分" << endl;
    cout << "\t\t\t\t\t0、退出" << endl;
}

//创建学生结构体
struct Student
{
    string ID; //学号
    string Name;  //姓名
    float Mark1;  //语文成绩
    float Mark2;  //数学成绩
    float Mark3;  //英语成绩
    float Mark4;  //计算机成绩
    float All;    //总分
    float Average;//平均成绩
};
//创建学生个体
struct Student stu[MAX];
int num = 0;   //计数器


void Copy(struct Student *arr)
{

}

//通过姓名来检索学生
int SearchByName(string name)
{
    for(int i = 0; i < num; i++)
    {
        if(stu[i].Name == name)
            return i;
    }
    return -1;
}

//通过学号来检索学生
int SearchByID(string id)
{
    for(int i = 0; i < num; i++)
    {
        if(stu[i].ID == id)
            return i;
    }
    return -1;
}

//重新输入要修改学生记录
void ModifyInput(int ans)
{
    cout << "请输入修改后的姓名：";
    cin >> stu[ans].Name;
    cout << "请输入修改后的学号：";
    cin >> stu[ans].ID;
    cout << "请输入修改后的语文成绩：";
    cin >> stu[ans].Mark1;
    cout << "请输入修改后的数学成绩：";
    cin >> stu[ans].Mark2;
    cout << "请输入修改后的英语成绩：";
    cin >> stu[ans].Mark3;
    cout << "请输入修改后的计算机成绩：";
    cin >> stu[ans].Mark4;
    stu[ans].All = stu[ans].Mark1 + stu[ans].Mark2 + stu[ans].Mark3 + stu[ans].Mark4;
    stu[ans].Average = stu[ans].All / 4;
}
//1、增加学生记录
void AddRecord()
{
    int flag = 1;
    while (flag)
    {
        cout << "请输入姓名：" ;
        cin >> stu[num].Name ;
        cout << "请输入学号：" ;
        cin >> stu[num].ID ;
        cout << "请输入语文成绩：" ;
        cin >> stu[num].Mark1 ;
        cout << "请输入数学成绩：" ;
        cin >> stu[num].Mark2 ;
        cout << "请输入英语成绩：" ;
        cin >> stu[num].Mark3 ;
        cout << "请输入计算机成绩：" ;
        cin >> stu[num].Mark4 ;
        stu[num].All = stu[num].Mark1 + stu[num].Mark2 + stu[num].Mark3 + stu[num].Mark4;
        stu[num].Average = stu[num].All / 4;
        num++;
        cout << "是否继续添加（0--退出  1--继续）：";
        cin >> flag;
    }
}

//2、修改学生记录
void ModifyRecord() {
    int sign;
    cout << "通过姓名查找（输入1）或是通过学号查找（输入2）：";
    while (true) {
        cin >> sign;
        if (sign == 1 || sign == 0)
            break;
        else
            cout << "输入格式错误，请重新输入：" << endl;
    }
    int ans;
    if (sign) {
        string name;
        cout << "请输入要修改的学生的姓名：";
        cin >> name;
        ans = SearchByName(name);
    } else
    {
        string id;
        cout << "请输入要修改的学生的学号：" ;
        cin >> id;
        ans = SearchByID(id);
    }
    if (ans >= 0) {
        ModifyInput(ans);
    } else
        cout << "查无此人" << endl;
}
//3、删除学生记录
void DeleteRecord()
{
    int sign;
    cout << "通过姓名查找（输入1）或是通过学号查找（输入0）：";
    while (true) {
        cin >> sign;
        if (sign == 1 || sign == 0)
            break;
        else
            cout << "输入格式错误，请重新输入" << endl;
    }
    int ans;
    if (sign) {
        string name;
        cout << "请输入要删除的学生的姓名：";
        cin >> name;
        ans = SearchByName(name);
    } else
    {
        string id;
        cout << "请输入要删除的学生的学号：" ;
        cin >> id;
        ans = SearchByID(id);
    }
    if(ans >= 0)
    {
        char c;
        cout << "是否确认删除：（y/n）";
        cin >> c;
        if(c == 'y')
        {
            num--;
            for(int i = ans; i < num; i++)
            {
                stu[i] = stu[i+1];
            }
            cout << "删除成功！" << endl;
        } else if(c == 'n')
            cout << "退出删除" << endl;
    } else
        cout << "查无此人" << endl;
}

//4、插入学生记录
void InsectRecord()
{
    int a;
    cout << "请输入要插入的位置：" ;
    cin >> a;
    a--;
    if(a < 0 || a > num)
        cout << "插入位置错误" << endl;
    else
    {
        for(int i = num; i > a; i--)
            stu[i] = stu[i-1];
        cout << "请输入姓名：" ;
        cin >> stu[a].Name ;
        cout << "请输入学号：" ;
        cin >> stu[a].ID ;
        cout << "请输入语文成绩：" ;
        cin >> stu[a].Mark1 ;
        cout << "请输入数学成绩：" ;
        cin >> stu[a].Mark2 ;
        cout << "请输入英语成绩：" ;
        cin >> stu[a].Mark3 ;
        cout << "请输入计算机成绩：" ;
        cin >> stu[a].Mark4 ;
        stu[a].All = stu[a].Mark1 + stu[a].Mark2 + stu[a].Mark3 + stu[a].Mark4;
        stu[a].Average = stu[a].All / 4;
        num++;
    }
}

//5、显示所有记录
void ShowRecord()
{
    for(int i = 0; i < num; i++)
    {
        cout << "第" << i+1 << "位" << "学生  " ;
        cout << "姓名：" << std::left << setw(6) << stu[i].Name;
        cout << "学号：" << setw(10) << stu[i].ID;
        cout << "语文成绩：" << setw(5) << stu[i].Mark1;
        cout << "数学成绩：" << setw(5) << stu[i].Mark2;
        cout << "英语成绩：" << setw(5) << stu[i].Mark3;
        cout << "计算机成绩：" << setw(5) << stu[i].Mark4;
        cout << "总分：" << setw(5) << stu[i].All;
        cout << "平均分：" << setw(5) << stu[i].Average;
        cout << endl;
    }
}

//6、查询学生记录
void CheckRecord()
{
    string name;
    cout << "请输入要查询的学生的姓名：" ;
    cin >> name;
    int index = SearchByName(name);
    if(index == -1)
        cout << "查无此人" << endl;
    else
    {
        cout << "第" << index+1 << "位" << "学生  " ;
        cout << "姓名：" << std::left << setw(6) << stu[index].Name;
        cout << "学号：" << setw(6) << stu[index].ID;
        cout << "语文成绩：" << setw(5) << stu[index].Mark1;
        cout << "数学成绩：" << setw(5) << stu[index].Mark2;
        cout << "英语成绩：" << setw(5) << stu[index].Mark3;
        cout << "计算机成绩：" << setw(5) << stu[index].Mark4;
        cout << "总分：" << setw(5) << stu[index].All;
        cout << "平均分：" << setw(5) << stu[index].Average;
        cout << endl;
    }

}

//7、按平均成绩排序
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

//8、输出各科目不及格的学生
void CheckLow()
{
    cout << "语文成绩不及格的学生：";
    for(int i = 0; i < num; i++)
    {
        if(stu[i].Mark1 < 60)
            cout << setw(6) << stu[i].Name;
        if(i % 5 == 0)
            cout << endl;
    }
    cout << endl;
    cout << "数学成绩不及格的学生：";
    for(int i = 0; i < num; i++)
    {
        if(stu[i].Mark2 < 60)
            cout << setw(6) << stu[i].Name;
        if(i % 5 == 0)
            cout << endl;
    }
    cout << endl;
    cout << "英语成绩不及格的学生：";
    for(int i = 0; i < num; i++)
    {
        if(stu[i].Mark3 < 60)
            cout << setw(6) << stu[i].Name;
        if(i % 5 == 0)
            cout << endl;
    }
    cout << endl;
    cout << "计算机成绩不及格的学生：";
    for(int i = 0; i < num; i++)
    {
        if(stu[i].Mark4 < 60)
            cout << setw(6) << stu[i].Name;
        if(i % 5 == 0)
            cout << endl;
    }
    cout << endl;
}

//9、输出各科目的最高分
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
    cout << "语文成绩最高分：";
    for(int i = 0; i < num; i++)
        if(stu[i].Mark1 == g1)
            cout << setw(10) << stu[i].Name;
    cout << endl;
    cout << "数学成绩最高分：";
    for(int i = 0; i < num; i++)
        if(stu[i].Mark2 == g2)
            cout << setw(10) << stu[i].Name;
    cout << endl;
    cout << "英语成绩最高分：";
    for(int i = 0; i < num; i++)
        if(stu[i].Mark3 == g3)
            cout << setw(10) << stu[i].Name;
    cout << endl;
    cout << "计算机成绩最高分：";
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
