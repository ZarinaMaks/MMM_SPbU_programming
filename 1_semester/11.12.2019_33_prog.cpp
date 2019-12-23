/*
 * Дана таблица  размером n * m.
 * Требуется найти в ней такую прямоугольную область, состоящую только из нулей, и среди всех таких — имеющую наибольшую площадь. 
 * Решение должно быть не медленнее чем O(n*m).
 */
 
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m; 
    stack<int> st;
    srand(time(0));
    
    vector < vector<int> > a (n, vector<int> (m));
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
		a[i][j]=(rand() % 2);
       // cout << " " << a[i][j] << endl;
    }
    
    for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j)
        cout << a[i][j] << " ";
    cout << endl;
    }
	
	int S = 0;
	vector<int> d (m, -1), d1 (m), d2 (m);
	for (int i = 0; i < n; ++i) {
	for (int j = 0; j < m; ++j)
		if (a[i][j] == 1)
			d[j] = i;
	while (!st.empty()) st.pop();
	for (int j = 0; j < m; ++j) {
		while (!st.empty() && d[st.top()] <= d[j])  st.pop();
		d1[j] = st.empty() ? -1 : st.top();
		st.push (j);
	}
	while (!st.empty()) st.pop();
	for (int j = m-1; j >= 0; --j) {
		while (!st.empty() && d[st.top()] <= d[j])  st.pop();
		d2[j] = st.empty() ? m : st.top();
		st.push (j);
	}
	for (int j = 0; j < m; ++j)
		S = max (S, (i - d[j]) * (d2[j] - d1[j] - 1));
	    
	}
	cout << endl << S;
    return 0;
}
