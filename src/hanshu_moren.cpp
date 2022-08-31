#include <iostream>
using namespace std;

/*
用法：如果参数传入了数据，就用传入的；没传，就用方法定义的默认的。

注意事项：
1.如果某个位置已经有了默认参数，那么从这个位置往后，从左到右都必须有默认值
所以下面的func2是错误的

2.函数声明和实现，只能有一个有默认参数。因为会造成程序有歧义
所以下面的func3是错误的
*/
int func(int a, int b = 20, int c = 30)
{
    return a + b + c;
}

// 错误
/*
int func2(int a = 20, int b, int c = 30)
{
    return a + b + c;
} */

// 这两个fun3只能有一个默认，都写就是错误
/*
int func3(int a = 10, int b = 20);
int func3(int a = 20, int b = 40)
{
    return a + b;
} */

// 占位参数
int func4(int)
{
    return 5;
}
// 占位参数默认值
int func5(int = 10)
{

    return 15;
}

/**
 * 函数默认参数
 *
 * @return int
 */
int main()
{
    // cout << func(10) << endl;      // 60
    // cout << func3(10, 200) << endl; // 240
    cout << func4(99) << endl;
    cout << func5() << endl;

    system("pause");
    return 0;
}