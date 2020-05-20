/* Создать класс с ~8 закрытыми полями.
 * Написать функции обращающиеся к этим закрытым полям.
*/
#include <iostream>
using namespace std;

class Point
{

private:
    int x1;  int y1;
    int x2=1; int x3=1; int x4=1;
    int y2=2; int y3=2; int y4=2;


public:

    Point()
    {
        x1=0;
        //x2=1; x3=1; x4=1;
        y1=0;
        //y2=2; y3=2; y4=2;
        cout << this << "constructor" << endl;
    }

    Point(int valueX, int valueY)
    {
        x1=valueX;  y1=valueY;
        //x2=valueX+1; x3=valueX+1; x4=valueX+1;
        //y2=valueY+1; y3=valueY+1; y4=valueY+1;
        cout << this << "constructor" << endl;
    }
    //void GetY(){return y1;}
    //void GetX(){return x1;}
    void Print ()
    {
        cout << "X = " << x1 << "\t Y = " << y1 << endl;
    }

    friend void ChangeX(Point &value);
    friend void ChangeY(Point &value);

};

//FRIEND function 1
void ChangeX(Point &value){
    value.x1 = x1+x2+x3+x4;
}

//FRIEND function 2
void ChangeY(Point &value){
    value.y1 = y1+y2+y3+y4;
}

int main()
{
    Point a(5,8);
    a.Print();

    ChangeX(a);
    a.Print();

    ChangeY(a);
    a.Print();

    return 0;
}
