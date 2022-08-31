#include <iostream>
using namespace std;

int &test01()
{
    static int ccc = 10;
    return ccc;
}

/**
 * 学习引用
 * 
 * @return int 
 */
int main()
{
    // int ref，这样写，就表示定义一个整形的ref，是一个明确的值
    // int &ref，这样写，就表示定义一个引用ref，是一个地址，指向test01的返回值
    // 这两种的区别一定记清楚
    int &ref = test01();
    cout << ref << endl; // 10
    cout << ref << endl; // 10

    test01() = 999;
    cout << ref << endl; // 999
    cout << ref << endl; // 999

    int aaa = 100;
    const int * p = &aaa;
    cout << *p << endl;

    system("pause");
    return 0;
}