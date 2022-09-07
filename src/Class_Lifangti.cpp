#include <iostream>
using namespace std;

/*
定义一个立方体，计算立方体的面积和体积
*/
class Cube
{
private:
    int chang;
    int kuan;
    int gao;

public:
    void setChang(int m_chang)
    {
        chang = m_chang;
    }
    void setKuan(int m_kuan)
    {
        kuan = m_kuan;
    }
    void setGao(int m_gao)
    {
        gao = m_gao;
    }
    int getChang()
    {
        return chang;
    }
    int getKuan()
    {
        return kuan;
    }
    int getGao()
    {
        return gao;
    }
    // 计算面积
    int calculateMianji()
    {
        return (chang * kuan + chang * gao + kuan * gao) * 2;
    }
    // 计算面积
    int calculateTiji()
    {
        return chang * kuan * gao;
    }

    // 利用成员函数判断两个立方体是否一样
    bool isSameOfClass(Cube &c2)
    {
        if (chang == c2.getChang() && kuan == c2.getKuan() && gao == c2.getGao())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// 全局函数判断是否一样。声明函数，判断两个立方体是否相等
bool isSame(Cube &c1, Cube &c2);

int main()
{
    Cube c1;
    c1.setChang(1);
    c1.setKuan(2);
    c1.setGao(3);
    int mianji = c1.calculateMianji();
    cout << "c1面积:" << mianji << endl; // 22
    int tiji = c1.calculateTiji();
    cout << "c2体积:" << tiji << endl; // 6

    Cube c2;
    c2.setChang(1);
    c2.setKuan(2);
    c2.setGao(3);

    Cube &c11 = c1;
    Cube &c22 = c2;

    bool f = isSame(c11, c22);
    if (f)
    {
        cout << "1111两个立方体一样" << endl;
    }
    else
    {
        cout << "1111两个立方体不一样" << endl;
    }
    // 参数直接写c2也可以，这里没看明白
    bool ff = c1.isSameOfClass(c2);
    if (ff)
    {
        cout << "2222两个立方体一样" << endl;
    }
    else
    {
        cout << "2222两个立方体不一样" << endl;
    }

    system("pause");
    return 0;
}

bool isSame(Cube &c1, Cube &c2)
{
    if (c1.getChang() == c2.getChang() && c1.getKuan() == c2.getKuan() && c1.getGao() == c2.getGao())
    {
        return true;
    }
    else
    {
        return false;
    }
}