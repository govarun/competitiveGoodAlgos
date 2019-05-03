#include <bits/stdc++.h>
using namespace std;

int getMaxElement(int arr[], int n){
    int max_element = arr[0];
    for(int i = 0; i < n; ++i){
        if(arr[i] > max_element){
            max_element = arr[i];
        }
    }
    return max_element;
}

void countSort(int arr[], int n, int pow10){
    // End digit refers to the Last digit of a no.
    // This approach involves storing each element in a vector of vectors according to its last digit
    // This approach is memory wise inefficient, see the optimized approach.
    vector <int> end_digit_index[10];
    
    for(int i = 0; i < n; ++i){
        end_digit_index[(arr[i] / pow10) % 10].push_back(i); // Indexes pushed
    }
    
    int arr_sorted[n];
    int current_index = 0;  // Current position in the sorted array
    for(int i = 0; i < 10; ++i){
        if(!end_digit_index[i].empty()){  // There is at least one element with i as last digit
            for(int j = 0; j < end_digit_index[i].size(); ++j){
                arr_sorted[current_index] = arr[end_digit_index[i][j]];
                ++current_index;
            }
        }
    }

    for(int i = 0; i < n; ++i){
        arr[i] = arr_sorted[i]; // Copying the sorted array into the original one
    }
}



void radixSort(int arr[], int n, int max_element){
    for(int pow10 = 1; pow10 <= max_element && pow10 <= INT_MAX; pow10 *= 10){
        countSort(arr, n, pow10);
    }

}

void printArray(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main(){
    int n; cin >> n; // n -> total no of elements
    int arr[n]; // Assuming the nos to be 32 bit, if they are 64 bit choose long long

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    int max_element = getMaxElement(arr, n);

    radixSort(arr, n, max_element);

    printArray(arr, n);
}