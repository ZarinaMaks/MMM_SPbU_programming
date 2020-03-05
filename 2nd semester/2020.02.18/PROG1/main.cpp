/* Написать структуру(не менее 10 полей),
 * и пару функций put_to_file(), get_from_file().
 */
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string path = "myFile.txt";

    //чтение из файла
    ifstream fin;
    fin.open(path);

    //запись в файл
    ofstream fout;
    fout.open(path,ofstream::app);


    if (!fin.is_open()){
        cout << "Opening file error!" << endl;
    }
    else {
        cout << "File was successfully opened!" << endl;

        //выводим считываемые файлы на экран:
        char ch;
        while(fin.get(ch)){
            cout << ch;
        }
        
        //записываем в файл элементы
        int a;
        cout << "Enter new numbers: " << endl;
        cin >> a;
        fout << a << "\n";
        
    }
    
    fin.close();
    fout.close();

    return 0;
