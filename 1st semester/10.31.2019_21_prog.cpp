/*На вещественную ось брошено N отрезков. Найти максимальное по включению множество непересекающихся отрезков.
В программе используется алгоритм быстрой сортировки и поиск минимальной базы матроида жадным способом.
*/
#include <iostream>
#include <cmath>
using namespace std;

struct Segments{
    int x;
    int y;
    int length;
};

void Qsort(struct Segments seg[], int left, int right) {
    int l = left, r = right;
    int X = seg[(left + right) / 2].length;
    while (l <= r) {
        while (seg[l].length < X){
            l++;}
            while (seg[r].length > X){
                r--;}
                if (l <= r) {
                    swap(seg[l], seg[r]);
                    l++;
                    r--;
                }
    };
    if (left < r){
        Qsort(seg, left, r);
        
    }
    if (l < right){
        Qsort(seg, l, right);
        
    }
};

int main() {
    int n;
    cin >> n;
    struct Segments seg[n];
    
    for(int i=0; i < n; i++){
        cin >> seg[i].x;
        cin >> seg[i].y;
        if(seg[i].x < seg[i].y){
            swap(seg[i].x, seg[i].y);
            
        }
        seg[i].length = abs(seg[i].x-seg[i].y);
    }
    
    Qsort(seg, 0, n-1);
    for(int i = 0; i < n ; i++) {
        cout << "(" << seg[i].y << "-" << seg[i].x << ");";
        
    }
    cout << endl;
    
    //поиск минимальной базы матроида
    int sum = 1;
    for(int i = 1, flag; i < n; i++, flag = 0){
    for(int k = 0; k <= i-1; k++){
        if(((seg[i].x<=seg[k].x)&&(seg[i].x>=seg[k].y))||((seg[i].x>=seg[k].x)&&((seg[i].x-seg[i].length)<seg[k].x))){
            flag = 0;
            
        }
        else{flag = 1;}
        
    }
    if(flag == 1){
        sum++;
        
    }
    }
    cout << "Disjoint segments: " << sum;
    return 0;
}
