/*Написать структуру хранящую рациональные числа в виде несократимых дробей.
Перегрузить арифметические операторы и операторы сравнений*/
#include <iostream>
using namespace std;

int nod(int a, int b){
    if ((a%b)>0){
        nod(b,a%b);
    }
    else if ((a%b)==0){return b;}
}

class fraction{
public:
    int a;
    int b;
    fraction(int x=0,int y=1);
    fraction(const fraction&);
    fraction& operator=(const fraction& C){
        this->a=C.a;
        this->b=C.b;
    }
    friend istream& operator>>(istream&,fraction&);
    friend ostream& operator<<(ostream&,const fraction&);
    fraction operator+=(const fraction&AA){
        this->a=this->a*AA.b+AA.a*this->b;
        this->b=this->b*AA.b;
        int gcd=nod(this->a,this->b);
        this->a=this->a/gcd;
        this->b=this->b/gcd;
        return *this;
    }
    fraction operator*=(const fraction& A){
        int gcd=nod(this->a*A.a,this->b*A.b);
        this->a=(this->a*A.a)/gcd;
        this->b=(this->b*A.b)/gcd;
        return *this;
    }
    };
    fraction::fraction(const fraction& C){
        a=C.a;
        b=C.b;
    }
    fraction::fraction(int x,int y){
        a=x/nod(x,y);
        b=y/nod(x,y);
    }
    istream& operator>>(istream& is,fraction&AA){
        is>>AA.a;
        is>>AA.b;
        int gcd=nod(AA.a,AA.b);
        AA.a=AA.a/gcd;
        AA.b=AA.b/gcd;
        return is;
    }
    ostream& operator<<(ostream &os,const fraction& AA){
        if((AA.a==AA.b)||AA.b==1){
            os<<AA.a;
        }else{
        os<<AA.a<<'/'<<AA.b;
    }
}
fraction operator+(const fraction& A,const fraction&B){
    fraction C;
    C=A;
    C+=B;
    return C;
}
fraction operator*(const fraction& AA,const fraction& BB){
    fraction C;
    C=AA;
    C*=BB;
    return C;
}
fraction operator+(int a,const fraction&B){
    fraction C;
    C.a=a;
    C.b=1;
    C+=B;
    return C;
}
fraction operator*(int a,const fraction& BB){
    fraction C;
    C.a=a;
    C*=BB;
    return C;
}
bool operator<(fraction AA,fraction BB){
    int a,b;
    a=(AA.a*BB.b);
    b=+(BB.a*AA.b);
    if(a<b){
        return true;
    }else {
        return false;
    }
}
bool operator==(fraction AA,fraction BB){
    int a,b;
    a=(AA.a*BB.b);
    b=(BB.a*AA.b);
    if(a==b){
        return true;
    }else {
        return false;
    }
}
int main()
{   fraction A,B,C;
    cin>>A>>B;
    cout<<A<<endl<<B<<endl;
    C=A+B;
    cout<<C<<endl;
    C=A*B;
    cout<<C<<endl;
    C=5+A;
    cout<<C<<endl;
    C=5*A;
    cout<<C<<endl;
    if(A==B){
        cout <<A<<"="<<B<<endl;
    }
    if(A<B){
        cout <<A<<'<'<<B<<endl;
    }
    if(!(A<B)&&!(A==B)){
        cout <<A<<'>'<<B<<endl;
    }
    if(!(A<B)&&(A==B)){
        cout <<A<<">="<<B<<endl;
    }
    if((A<B)&&(A==B)||(A==B)){
        cout <<A<<"<="<<B<<endl;
    }
    return 0;
}
