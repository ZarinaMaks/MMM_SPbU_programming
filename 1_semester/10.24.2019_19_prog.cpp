//Провести эксперимент для сортировки выбором.
//Экспериментально определить отношение между сравнением и swap
#include <iostream>
#include <cstdlib>
#define swap_time 0.09
#define greater_time 0.0001
using namespace std;

void Qsort(int arr[], int left, int right,double& sum_swap_time1,double& sum_compare_time1, double t_swap, double t_greater) {
    int i = left, j = right;
    int X = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < X){
            sum_compare_time1+=t_greater;
            i++;
            
        }
        while (arr[j] > X){
            sum_compare_time1+=t_greater;
            j--;}
            if (i <= j) {
                swap(arr[i],arr[j]);
                i++;
                j--;
                sum_swap_time1+=t_swap;
                
            }
    };
    if (left < j){
        
        Qsort(arr, left, j, sum_swap_time1, sum_compare_time1, t_swap, t_greater);
    }
}

void selection(int arr[],int n,double& sum_swap_time2, double& sum_compare_time2,double t_swap,double t_greater){
    int min;
    for(int i = 0; i < n-1; i++){
        min=i;
        for(int j = i+1; j < n; j++){
            sum_compare_time2+=t_greater;
            if(arr[j]<arr[min]){
                min=j;
                
            }
            
        }
        if(min!=i){
            swap(arr[i],arr[min]);
            sum_swap_time2+=t_swap;
            
        }
    }
}

int main(int argc, const char * argv[]) {
    int n;
        cin >> n;
    double t_swap,t_greater;
    t_swap=swap_time;
    t_greater=greater_time;
    double ratio;
    double sum_swap_time1=0,sum_compare_time1=0,sum_swap_time2=0,sum_compare_time2=0;
    ratio=0; sum_swap_time1=0; sum_compare_time1=0; sum_swap_time2=0; sum_compare_time2=0;
    int A[n], B[n];
    for(int j=0; j<n; A[j++]=rand()%1000);
    for(int k=0; k<n; k++){
        B[k]=A[k];
        
    }
    Qsort(A, 0, n-1, sum_swap_time1, sum_compare_time1, t_swap, t_greater);
    selection(B,n,sum_swap_time2,sum_compare_time2,t_swap,t_greater);
    ratio=(sum_swap_time1 + sum_compare_time1)/(sum_swap_time2 + sum_compare_time2); 
    cout << ratio << endl;
    return 0;
}