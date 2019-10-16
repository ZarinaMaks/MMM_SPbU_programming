/*
Написать функции проверяющие является ли число:
Числом Мерсена
Числом Ферма
Числом Вильсона
Числом Вагстафа
Числом Вивериха
Числом Софи Жермен
Числом Хиггса
*/
#include <iostream>
using namespace std;

//vozvedenie v stepen'
int power(int a, int b) {
    int s=1;
    for(int i=0; i < b; i++) {
        s=s*a;
    }
    return s;
}

//factorial
long int fact(long int N) {
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
};

//proverki chisla
bool wilson(int n) {
    int s=1;
    for(int k=1; k<n; k++){
       s=(s*k)%(n*n);
    }
    if ((s+1)%(n*n)==0){
        return true;
    }
    return 0;
    return false;
}

bool wieferich(int n) {
    int s=2;
    for(int k=1; k < n-1; k++){
       s=(s*2)%(n*n);
    }
    if (s==1){
        return true;
    }
    return false;
}

bool mersenn(int n) {
    n=n+1;
    for(int k=2; k<=n; k=k*2) {
        if(k==n){
            return true;
        }
    }
    return false;
};

bool ferma(int n) {
    n=n-1;
    for(int k=2; k<=n; k=k*2){
        if(k==n){
            return true;
        }
    }
    return false;
};

bool wilson( int );
int power(int a, int b, int prost[]) {
    int s=a;
    for(int j=1; j<prost[b]; j++){
        s=s*a;
    }
    return s;
}

bool wagstaff(int n, int prost[]) {
    for(int i=0;(1+power(2, i, prost))<=3*n;i++){
        if(3*n==(1+power(2, i, prost))){
            return true;
        }
    }
    return false;
}

bool sophie(int p, bool v[]) {
    if(v[2*p+1]){
        return true;
    }
    return false;
}

/*
bool higgs(int a,int higgs[],int count){
int s=1;
for(int i=1;(i<count)||(higgs[i]<a);i++){
s=higgs[i-1]*s;
if((s*s)%(higgs[i]-1)!=0){
higgs[i]=1;
}
if((s*s)%(a-1)==0){
cout«s«endl;
return true;
}
}
return false;
}
*/

bool higgs(int a, int higgs[], int count) {
    for(int i=1; (i<count)&&(higgs[i]<=a); i++){
        int s=1;
        for(int j=0; j<i;j++){
            s=(s*higgs[j]*higgs[j])%(higgs[i]-1);
            
        }
        if(s!=0){
            higgs[i]=1;
        }

        for(int k=0;(k<=i)&&(a<=higgs[i]);k++){
            if(a==higgs[k]){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int k, count=0, x;
    cin >> x;
    k=2*x+100;
    
    bool v[k+1];
    for(int i=2; i<k+1; v[i++]=1);
    for(int i=2; i<k+1; i++){
        if(v[i]){
            count++;
            for(int j=i*2; j<k+1; j+=i){
                v[j]=0;
        }
    }
}
    //sozdaem massiv prostih chisel
    //v[] - proverka na prostotu
    int prost[count];
    for(int i=2, j=0; i<k+1; i++){
        if(v[i]) {
            prost[j]=i;
            j++;
        }
    }
    
    if(mersenn(x)){
        cout << x << " - chislo mersenna" << endl;
    };
    
    if(ferma(x)){
        cout << x << " - chislo ferma" << endl;
    }
    
    if(v[x]){
        if(wieferich(x)){
            cout << x << " - chislo wiefericha" << endl;
        }
    }

    if(v[x]){
        if(wilson(x)){
            cout << x << " - chislo vilsona" << endl;;
        }
    }

    if(wagstaff(x, prost)){
        cout << x <<" - chislo wagstaffa" << endl;
    }
    
    if(v[x]){
        if(sophie(x,v)){
            cout << x << " - chislo sophie germain" << endl;
        }
    }
    if(v[x]){
        if(higgs(x, prost,count)) {
            cout << x << " - chislo higgsa"<<endl;
        }
}
    return 0;
};
