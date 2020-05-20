/*(10 баллов) Возьмите одну из старых программ, создайте makefile для её сборки в файл MyProg.
Придумайте не менее 10 тестов к ней и запишите их в файлы 1_test_in.txt, 2_test_in.txt,... 
результаты их выполнения 1_test_Result.txt,2_test_Result.txt,...
Напишите bash-скрипт, который: 
-собирает с помощью makefile MyProg из текущей директории
-запускает MyProg на всех тестах записывая результаты в 1_test_out.txt,2_test_out.txt,...
- сравнивает файлы *_Result.txt с *_out.txt
Выписывает количество пройденных тестов
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include <stack>
#include <cmath>

using namespace std;

void Braces(string a, const char*Result)
{
    stack <char> Brace;
    
    ofstream fout(Result);
    
    if ((a[0]=='(')||(a[0]=='[')) 
    {
        Brace.push(a[0]);
        
    }
    else
    {
        fout<<"No";
        return;
        
    }
    for (int i=1; i< a.size(); i++)
    {
        if ((a[i]=='(')||(a[i]=='[')) 
        {
            Brace.push(a[i]);
            
        }
        else {
            if (Brace.empty())
            {
                fout<<"No";
                return;
                
            }
            if ((!Brace.empty())&&(abs(a[i]-Brace.top())<3)) 
            {
                Brace.pop();
                
            }
            else 
            {
                fout<<"No";
                return;
                
            }
            
        }
        
    }
    
    if (Brace.empty()) 
    {
        fout<<"Yes";
        
    }
    else 
    {
        fout<<"No";
        fout.close();
    }
    }
    
    
    int main()
    {
        char k='0';
        for (int i = 1; i < 11; i++)
        {
            char Path1[]="0_test_in.txt";
            char Result1[]="0_test_res.txt";
            const char*Path;
            const char*Result;
            if (k!='9') { k++;
            Path1[0]=k;
            Result1[0]=k;
            Path=Path1;
            Result=Result1;
                
            }
            else 
            {
                Path="10_test_in.txt";
                Result="10_test_res.txt";
                
            }
            
            ifstream fin(Path);
            string test;
            fin>>test;
            fin.close();
            Braces(test,Result);
            cout<<endl;
            
        }
        return 0;
        
    }