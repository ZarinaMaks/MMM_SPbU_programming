//На окружности заданы N точек, надо найти три точки такие, что площадь натянутого на них треугольника максимальна.
//Программа должна работать за время не большее O(N) 
#include <iostream>
#include <math.h>
using namespace std;

double area(int A, int B, int C, double *c){
    return abs((cos(c[B])-cos(c[A]))*(sin(c[C])-sin(c[A]))-(cos(c[C])-cos(c[A]))*(sin(c[B]))-sin(c[A]));
}
double area(double *l){
    return 5;
}
int main(int argc, const char * argv[]) {
    int i;
    cin>>i;
    double angle[i];
    for(int j=0;j<i;cin>>angle[j++]){};
    for(int j=0;j<i;cout<<angle[j++]<<endl){};
    int A,B,C,maxA,maxB,maxC;
    A=0;
    B=1;
    C=2;
    maxA=A;
    maxB=B;
    maxC=C;
    for(;A<i;A++){
        while (area(A,B,C,angle)<=area(A,B,(C+1)%i,angle)){
            C=(C+1)%i;
            if(area(A,B,C,angle)>=area(maxA,maxB,maxC,angle)){
                               maxA=A;
                               maxB=B;
                               maxC=C;
            while (area(A,B,C,angle)<=area(A,(B+1)%i,C,angle)){
                B=(B+1)%i;
                if(area(A,B,C,angle)>=area(maxA,maxB,maxC,angle)){
                    maxA=A;
                    maxB=B;
                    maxC=C;
                }
            }
        }
    }
}
    cout<<"angles:"<<angle[maxA]<<";"<<angle[maxB]<<";"<<angle[maxC]<<endl;
    return 0;
}