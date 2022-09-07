#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string id;
    string name;

protected:
    string car;

private:
    int pwd;

private:
    void publicFunc(string name1)
    {
        // 类内都可以访问
        name = name1;
        car = "奔驰";
        pwd = 123456;
    }

public:
    void sysout(string mcar)
    {
        car = mcar;
        cout << id << "," << name << "," << car << "," << endl;
        cout << "pwd:" << pwd << endl;
    }
};

struct Animal
{
    int eye;
    int mouth;
    int leg;

    void setEye(int a)
    {
        eye = a;
    }
    void setMonth(int b)
    {
        mouth = b;
    }
    void setLeg(int c)
    {
        leg = c;
    }

    void soutAnimal()
    {
        cout << eye << "," << mouth << "," << leg << endl;
    }
};

int main()
{
    Person person;
    // 私有访问不了
    // person.publicFunc("小红他");
    // person.pwd = 654321;
    person.id = "9999999999";

    person.sysout("玛莎拉蒂");

    Animal animal;
    animal.eye = 2;
    animal.setLeg(4);
    animal.setMonth(1);
    animal.soutAnimal();

    system("pause");
    return 0;
}