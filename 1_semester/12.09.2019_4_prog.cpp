#include <iostream>
#include <string>
using namespace std;

struct Person {
string Name;
int age;
};

void sort(Person** q, int n) {
for (int i = 0; i < n; i++)
for (int j = 0; j < n - i - 1; j++)
if (q[j]->age > q[j + 1]->age)
{
Person* temp = q[j];
q[j] = q[j + 1];
q[j + 1] = temp;
}
}

int main() {
int n = 3;
Person* p = new Person[n];
for (int i = 0; i < n; i++)
cin >> p[i].Name >> p[i].age;
Person** q = new Person * [n];
for (int i = 0; i < n; i++)
q[i] = &p[i];
sort(q, n);
for (int i = 0; i < n; i++)
cout << q[i]->Name << q[i]->age <<"\n";

return 0;
}

