#include <iostream>
#include <string>
using namespace std;

// 宏常量，定义通讯录中的最大人数
#define MAX 1000

// 定义联系人结构体
struct Person
{
    // 姓名
    string name;
    // 性别。1男，2女
    int m_Sex;
    // 年龄
    int age;
    // 电话
    string phone;
    // 住址
    string address;
};

// 通讯录结构体
struct Addressbooks
{
    // 通讯中中保存的联系人数组
    Person personArr[MAX];

    // 通讯录中记录的联系人个数
    int m_Size;
};

// 显示菜单
void showMenu();

// 添加联系人
void addPerson(Addressbooks *abs);

// 显示全部联系人
void showPerson(Addressbooks *abs);

// 检测联系人是否存在
int checkPersonExist(Addressbooks *abs, string name);

// 删除联系人
void deletePerson(Addressbooks *abs);

// 修改联系人
void editPerson(Addressbooks *abs);

// 查找联系人
void searchPerson(Addressbooks *abs);

// 清空联系人
void clearPerson(Addressbooks *abs);

/**
 * 通讯录小功能
 * 
 * @return int 
 */
int tongxunlu()
{
    // 创建通讯录的结构体变量
    Addressbooks abs;
    abs.m_Size = 0;

    while (true)
    {
        showMenu();
        cout << "请选择功能~~" << endl;
        int select = 0;
        cin >> select;
        switch (select)
        {
        case 1:
            // 添加联系人
            addPerson(&abs);
            break;
        case 2:
            // 显示全部联系人
            showPerson(&abs);
            break;
        case 3:
            // 删除联系人
            deletePerson(&abs);
            break;
        case 4:
            // 查找联系人
            searchPerson(&abs);
            break;
        case 5:
            // 修改联系人
            editPerson(&abs);
            break;
        case 6:
            // 清空联系人
            clearPerson(&abs);
            break;
        case 999:
            // 退出通讯录
            cout << "欢迎下次使用！" << endl;
            system("pause");
            return 0;
            break;
        default:
            cout << "输入错误，请重新输入！！！" << endl;
            break;
        }
    }

    return 0;
}

// 添加联系人
void addPerson(Addressbooks *abs)
{
    // 判断通讯录是不是已经满了
    if (abs->m_Size >= MAX)
    {
        cout << "通讯录已满，无法添加！！" << endl;
        return;
    }

    // 新建一个person实例
    Person person;

    // cin给实例各属性赋值

    // 请输入姓名
    string name;
    cout << "请输入姓名：" << endl;
    cin >> name;
    person.name = name;

    // 请输入性别
    int sex;
    cout << "请输入性别（1男、2女）：" << endl;
    while (true)
    {
        cin >> sex;
        if (sex != 1 && sex != 2)
        {
            cout << "请正确输入：1男、2女" << endl;
        }
        else
        {
            break;
        }
    }
    person.m_Sex = sex;

    // 请输入年龄
    int age;
    cout << "请输入年龄：" << endl;
    cin >> age;
    person.age = age;

    // 请输入电话
    string phone;
    cout << "请输入电话：" << endl;
    cin >> phone;
    person.phone = phone;

    // 请输入住址
    string address;
    cout << "请输入住址：" << endl;
    cin >> address;
    person.address = address;

    // 取出当前是第几个元素，保存到abs中
    abs->personArr[abs->m_Size] = person;

    // 数组下标+1
    abs->m_Size = (abs->m_Size + 1);

    cout << "添加联系人成功!!" << endl;

    // 清屏
    system("cls");
}

// 修改联系人
void editPerson(Addressbooks *abs)
{
    string name;
    cout << "请输入联系人姓名：" << endl;
    cin >> name;

    int index = checkPersonExist(abs, name);

    if (index != -1)
    {
        Person person;
        cout << "请输入姓名：" << endl;
        cin >> name;
        person.name = name;

        // 请输入性别
        int sex;
        cout << "请输入性别（1男、2女）：" << endl;
        while (true)
        {
            cin >> sex;
            if (sex != 1 && sex != 2)
            {
                cout << "请正确输入：1男、2女" << endl;
            }
            else
            {
                break;
            }
        }
        person.m_Sex = sex;

        // 请输入年龄
        int age;
        cout << "请输入年龄：" << endl;
        cin >> age;
        person.age = age;

        // 请输入电话
        string phone;
        cout << "请输入电话：" << endl;
        cin >> phone;
        person.phone = phone;

        // 请输入住址
        string address;
        cout << "请输入住址：" << endl;
        cin >> address;
        person.address = address;

        // 取出当前是第几个元素，保存到abs中
        abs->personArr[index] = person;

        cout << "联系人修改成功！" << endl;

        system("pause");
        // 清屏
        system("cls");
        return;
    }
    system("pause");
    system("cls");
}

void showPerson(Addressbooks *abs)
{
    if (abs->m_Size == 0)
    {
        cout << "暂无联系人！" << endl;
        system("pause");
        // 清屏
        system("cls");
        return;
    }
    for (int i = 0; i < abs->m_Size; i++)
    {
        Person itemPerson = abs->personArr[i];
        cout << "姓名:" << itemPerson.name << "，"
             << "性别:" << (itemPerson.m_Sex == 1 ? "男" : "女") << "，"
             << "年龄:" << itemPerson.age << "，"
             << "电话:" << itemPerson.phone << "，"
             << "住址:" << itemPerson.address << endl;
    }
    system("pause");
    // 清屏
    system("cls");
}

// 查找联系人
void searchPerson(Addressbooks *abs)
{
    string name;
    cout << "请输入联系人姓名：" << endl;
    cin >> name;

    int index = checkPersonExist(abs, name);

    if (index != -1)
    {
        Person itemPerson = abs->personArr[index];
        cout << "姓名:" << itemPerson.name << "，"
             << "性别:" << (itemPerson.m_Sex == 1 ? "男" : "女") << "，"
             << "年龄:" << itemPerson.age << "，"
             << "电话:" << itemPerson.phone << "，"
             << "住址:" << itemPerson.address << endl;
        system("pause");
        // 清屏
        system("cls");
        return;
    }
    system("pause");
}

// 检测联系人是否存在
int checkPersonExist(Addressbooks *abs, string name)
{
    if (abs->m_Size == 0)
    {
        cout << "通讯录为空！" << endl;
        return -1;
    }
    for (int i = 0; i < abs->m_Size; i++)
    {
        // 取出每一个姓名，判断和输入的是否一致
        string txlName = abs->personArr[i].name;
        if (name == txlName)
        {
            return i;
        }
    }
    cout << "联系人不存在！" << endl;
    return -1;
}

// 删除联系人
void deletePerson(Addressbooks *abs)
{
    string name;
    cout << "请输入联系人姓名：" << endl;
    cin >> name;

    int index = checkPersonExist(abs, name);

    // 删除思路，将数据往前移，然后m_Size-1
    // 王五的数据盖李四的数据，赵六的数据盖住王五的数据

    if (index != -1)
    {
        // 取出现在一共多少个人
        int size = abs->m_Size;
        for (int i = index; i < size; i++)
        {
            // 取出来后面的Person
            Person hou = abs->personArr[index + 1];

            // 覆盖前面的Person
            abs->personArr[index] = hou;
        }
        abs->m_Size = abs->m_Size - 1;
        cout << "删除联系人" << name << "完成" << endl;
        system("pause");
        system("cls");
    }
}

// 清空联系人
void clearPerson(Addressbooks *abs)
{
    if (abs->m_Size == 0)
    {
        cout << "暂无联系人" << endl;
        return;
    }
    // 这样。就行，逻辑清空
    abs->m_Size = 0;
    cout << "清空联系人成功！" << endl;
    system("pause");
    system("cls");
}

// 显示菜单
void showMenu()
{
    cout << "********************************" << endl;
    cout << "********* 1.添加联系人 *********" << endl;
    cout << "********* 2.显示联系人 *********" << endl;
    cout << "********* 3.删除联系人 *********" << endl;
    cout << "********* 4.查找联系人 *********" << endl;
    cout << "********* 5.修改联系人 *********" << endl;
    cout << "********* 6.清空联系人 *********" << endl;
    cout << "********* 999.退出通讯录 *******" << endl;
    cout << "********************************" << endl;
}