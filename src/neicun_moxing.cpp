#include <iostream>
using namespace std;

int *fun()
{
    // 使用new关键字，在堆区创建对象
    // 利用new创建的数据，会返回该数据对应的类型的指针
    int *p = new int(10);
    return p;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int *p = fun();
    cout << *p << endl;
    cout << *p << endl;

    // new一个数组
    int *arr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        // 给每个元素赋值
        arr[i] = i + 100;
    }

    // 读取每个元素
    for (int i = 0; i < 10; i++)
    {
        cout << "元素:" << arr[i] << endl;
    }

    // 释放对象
    delete p;
    delete[] arr;

    // --------------------------------------------

    int aaa = 20;
    int ccc = 55;
    cout << "aaa1:" << aaa << endl; // 20
    int &b = aaa;
    // 这是赋值操作，不是更改引用，所以是可以的
    b = ccc;

    cout << "b:" << b << endl;      // 2000
    cout << "aaa2:" << aaa << endl; // 2000

    // --------------------------------------------

    int s1 = 77;
    int s2 = 88;
    cout << "s1:" << s1 << endl; // 77
    cout << "s2:" << s2 << endl; // 88
    swap(s1, s2);
    cout << "s1:" << s1 << endl; // 88
    cout << "s2:" << s2 << endl; // 77

    // --------------------------------------------

    system("pause");
    return 0;
}