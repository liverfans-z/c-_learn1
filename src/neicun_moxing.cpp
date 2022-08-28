#include <iostream>
using namespace std;

int *fun()
{
    // 使用new关键字，在堆区创建对象
    int *p = new int(10);
    return p;
}

int main()
{
    int *p = fun();
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    system("pause");
    return 0;
}