#include <iostream>
using namespace std;

const double PI = 3.14;

// 定义一个类，关键词，class
class Circle
{
public:
    // 属性
    // 半径
    int m_r;

    // 行为
    // 计算周长
    double calculateZc()
    {
        return 2 * PI * m_r;
    }
};

/**
 * 第一次学习类
 *
 * @return int
 */
int main()
{
    // 通过圆这个类，创建具体的圆
    // 实例化（通过类创建对象的过程）
    Circle c1;

    // 给圆的属性赋值
    c1.m_r = 10;

    // 调用圆的方法，计算周长
    double zc = c1.calculateZc();
    cout << "周长:" << zc << endl;

    system("pause");

    return 0;
}