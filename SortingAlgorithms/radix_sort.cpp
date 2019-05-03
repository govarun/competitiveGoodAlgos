#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n, int pow10){
    vector <int> end_dig_index[10];
    for(int i = 0; i < n; ++i){
        end_dig_index[(arr[i] / pow10) % 10].push_back(i);
    }
    int arr_sorted[n];
    int cur_index = 0;
    for(int i = 0; i < 10; ++i){
        if(!end_dig_index[i].empty()){
            for(int j = 0; j < end_dig_index[i].size(); ++j){
                arr_sorted[cur_index] = arr[end_dig_index[i][j]];
                cur_index++;
            }
        }
    }

    for(int i = 0; i < n; ++i){
        arr[i] = arr_sorted[i];
    }
}



void radixSort(int arr[], int n, int max_element){
    for(int pow10 = 1; pow10 <= max_element && pow10 <= INT_MAX; pow10 *= 10){
        countSort(arr, n, pow10);
    }

}
int main(){
    int n; cin >> n; // n - total no of elements

    int arr[n]; // Assuming the nos to be 32 bit, if they are 64 bit choose long long
    int max_element = INT_MIN;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        max_element = max(max_element, arr[i]);
    }

    radixSort(arr, n, max_element);

    for(int i = 0; i < n; ++i){
        cout << arr[i] << ' ';
    }
}
