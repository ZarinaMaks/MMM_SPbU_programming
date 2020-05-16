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
  /*  //чтение из файла:
    ifstream fin;
    fin.open(path);
    //запись в файл:
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
        //записываем в файл элементы:
        int a;
        cout << "Enter new numbers: " << endl;
        cin >> a;
        fout << a << "\n";
    }
    fin.close();
    fout.close();
    */

  fs fstream fs;
  fs.open (path, fstream::in | fstream::out | fstream::app);
  if (!fs.is_open())
  {
      cout << "Opening myFile error!" << endl;
  }
  else
      {
      string msg;
      int value;
      cout << "MyFile was successfully opened!" << endl;
      cout << "Press 0 for saving entered numbers to file. " << endl;
      cout << "Press 1 for reading all numbers from file. " << endl;
      cin >> value;

=======
  
  fs fstream fs;
  fs.open (path, fstream::in | fstream::out | fstream::app);
  if (!fs.is_open())
  {
      cout << "Opening myFile error!" << endl;
  }
  else
      {
      string msg;
      int value;
      cout << "MyFile was successfully opened!" << endl;
      cout << "Press 0 for saving entered numbers to file. " << endl;
      cout << "Press 1 for reading all numbers from file. " << endl;
      cin >> value;

      if (value == 0)
      {
          cin >> msg;
          fs << msg<< "\n";

      }
      if (value == 1)
      {
          cout << "myFile consists of: " << endl;
          while (!fs.eof())
          {
              msg ="";
              fs >> msg;
              cout << msg << endl;

          }
      }

  }
    fs.close();
    return 0;
}