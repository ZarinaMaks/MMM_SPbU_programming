// Реализовать структуру String для работы со строками. 
// Структура должна удовлетворять правилу Трех и содержать методы поиска подстроки и конкатенации(как оператор+)
#include <iostream>
#include <cstring>

using namespace std;

class myStr{
private:
    unsigned int len;
    char* str;
public:
    myStr(){
        len = 8;
        str = new char[len];
        strcpy(str, "default");
    }
    myStr(char* S){
        len = strlen(S);
        str = new char[len + 1];
        strcpy(str, S);
        str[len] = '\0';
    }
    ~myStr(){
        delete[] str;
    }
    myStr& operator=(const myStr& other)
    {
        if (this == &other)
            return *this;

        char* tmp_str = new char[strlen(other.str) + 1];
        strcpy(tmp_str, other.str);
        delete[] str;
        str = tmp_str;
        return *this;
    }
    unsigned int length(){
        return len;
    }

    bool substr(myStr sub_str){
        int i, j;
        for(i = 0; i < len; i++){
            for(j = i; j < sub_str.length() + i; j++){
                if(str[j] != sub_str.str[j - i])
                    break;
                else if(str[j] == sub_str.str[j - i] && j - i + 1 == sub_str.length()){
                    cout<<"exist";
                    return true;
                }
            }
        }
        cout<<"do not exist";
        return false;
    }
    void plus(myStr second){
        unsigned int new_len = len + second.length();
        char* new_str = new char[new_len];
        for(int i = 0; i < new_len; i++){
            if(i < len)
                new_str[i] = str[i];
            else
                new_str[i] = second.str[i - len];
        }
        str = new_str;
        len = new_len;
    }
};


int main() {
    cout << "Hello, World!" << endl;
    myStr str = myStr("asdf");
    cout<<str.length();
    return 0;
}
