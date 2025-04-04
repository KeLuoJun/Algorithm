//
// Created by Honor on 2023/12/28.
//
#include "iostream"
#include "string"
using namespace std;
#define MAX 1000
//菜单界面
void showMenu()
{
    cout << "********************" << endl;
    cout << "*****1、添加联系人*****" << endl;
    cout << "*****2、显示联系人*****" << endl;
    cout << "*****3、删除联系人*****" << endl;
    cout << "*****4、查找联系人*****" << endl;
    cout << "*****5、修改联系人*****" << endl;
    cout << "*****6、清空联系人*****" << endl;
    cout << "*****0、退出通讯录*****" << endl;
    cout << "********************" << endl;
}

//建立联系人结构体
struct Person
{
    //姓名
    string m_Name;
    //性别 1 男 2 女
    int m_Sex;
    //年龄
    int m_Age;
    //电话
    string m_Phone;
    //住址
    string m_Addr;
};

//设计通讯录结构体
struct Addressbooks
{
    //通讯录中保存的联系人数组
    struct Person personArray[MAX];
    //通讯录中当前记录联系人个数
    int m_Size;
};

//1、添加联系人
void addPerson(Addressbooks *abs)
{
    //判断通讯录是否已满，如果满了就不再添加
    if(abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加！" << endl;
        return;
    } else
    {
        //添加具体联系人

        //姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;
        //性别
        int sex = 0;
        cout << "请输入性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        while (true)
        {
            cin >> sex;
            if(sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            } else {
                cout << "输入有误，请重新输入" << endl;
            }
        }
        //年龄
        cout << "请输入年龄：" << endl;
        int age;
        while (true)
        {
            cin >> age;
            if(age > 0 && age < 150)
            {
                abs->personArray[abs->m_Size].m_Age = age;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }
        //电话
        cout << "请输入电话号码：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;
        //住址
        cout << "请输入住址：" << endl;
        string addr;
        cin >> addr;
        abs->personArray[abs->m_Size].m_Addr = addr;
        //更新通讯录人数
        abs->m_Size++;

        cout << "添加成功！" << endl;

        system("pause"); //请按任意键继续
        system("cls");   //清屏操作
    }
}

//2、显示联系人
void showPerson(Addressbooks *abs)
{
    if(abs->m_Size == 0)
            cout << "当前记录为空" << endl;
    else
    {
        for(int i = 0; i < abs->m_Size; i++)
        {
            cout << "姓名：" << abs->personArray[i].m_Name << "\t";
            cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女")<< "\t";
            cout << "年龄：" << abs->personArray[i].m_Age << "\t";
            cout << "电话：" << abs->personArray[i].m_Phone << "\t";
            cout << "住址：" << abs->personArray[i].m_Addr << endl;
        }
        system("pause"); //请按任意键继续
        system("cls");   //清屏操作
    }
}

//检测联系人是否存在，如果存在，返回联系人所在数组中的位置，不存在返回-1
int isExist(Addressbooks *abs, string name)
{
    for(int i = 0; i < abs->m_Size; i++)
    {
        if(abs->personArray[i].m_Name == name)
        {
            return i;  //找到了，返回这个人在数组中的位置编号
        }
    }
    return -1;
}

//3、删除联系人
void deletePerson(Addressbooks *abs)
{
    cout << "请输入要删除的联系人：" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs,name);
    if(ret != -1)
    {
        for(int i = ret; i < abs->m_Size; i++)
        {
            //数据迁移
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_Size--;
        cout << "删除成功！" << endl;
    } else
        cout << "查无此人" << endl;
    system("pause");
    system("cls");
}

//4、查找指定联系人信息
void findPerson(Addressbooks *abs)
{
    cout << "请输入您要查找的联系人：" << endl;
    string name;
    cin >> name;
    //判断指定的联系人是否在通讯录里
    int ret = isExist(abs,name);
    if(ret != -1) //找到联系人
    {
        cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
        cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女");
        cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
        cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
        cout << "住址：" << abs->personArray[ret].m_Addr << "\t";
    }
    else
        cout << "查无此人！" << endl;
    system("pause");
    system("cls");
}

//5、修改指定联系人信息
void modifyPerson(Addressbooks *abs)
{
    cout << "请输入您要修改的联系人：" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs,name);
    if(ret != -1)
    {
        //姓名
        cout << "请输入姓名：" << endl;
        string name1;
        cin >> name1;
        abs->personArray[ret].m_Name = name1;
        //性别
        cout << "请输入性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if(sex == 1 || sex == 2)
            {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }
        //年龄
        cout << "请输入年龄：" << endl;
        int age;
        cin >> age;
        abs->personArray[ret].m_Age = age;
        //电话
        cout << "请输入电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;
        //住址
        cout << "请输入住址：" << endl;
        string addr;
        cin >> addr;
        abs->personArray[ret].m_Addr = addr;

        cout << "修改成功！" << endl;
    } else{
        cout << "查无此人" << endl;
    }
}

//6、清空联系人
void cleanPerson(Addressbooks *abs)
{
    cout << "是否确认清空联系人" << endl;
    cout << "1 --- 确认" << endl;
    cout << "2 --- 返回" << endl;
    int flag;
    cin >> flag;
    if(flag == 1)
    {
        abs->m_Size = 0; //将当前记录联系人数量重置为0，做逻辑清空操作
        cout << "通讯录已清空！" << endl;
    } else
    {
        cout << "清空联系人失败" << endl;
    }

    //按任意键后清屏
    system("pause");
    system("cls");

}


int main()
{
    //创建通讯录结构体变量
    Addressbooks abs;
    //初始化通讯录中当前人员个数
    abs.m_Size = 0;
    //创建用户选择输入的变量
    int select = 0;
    while(true)
    {
        showMenu();  //菜单调用
        cin >> select;
        switch (select) {
            case 1:
                addPerson(&abs); //利用地址传递
                break;
            case 2:
                showPerson(&abs);
                break;
            case 3:
                deletePerson(&abs);
                break;
            case 4:
                findPerson(&abs);
                break;
            case 5:
                modifyPerson(&abs);
                break;
            case 6:
                cleanPerson(&abs);
                break;
            case 0:
                cout << "欢迎下次使用" << endl;
                system("pause");
                return 0;
            default:
                break;
        }
    }
}
