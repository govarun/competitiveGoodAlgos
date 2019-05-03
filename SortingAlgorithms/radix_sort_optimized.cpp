#include <bits/stdc++.h>
using namespace std;


void countSort(int arr[], int n, int pow10){
    int freq_end_dig[10]; // To store the count of each end digit
    memset(freq_end_dig, 0, sizeof(freq_end_dig));

    for(int i = 0; i < n; ++i){
        freq_end_dig[(arr[i] / pow10) % 10]++;
    }
    for(int i = 1; i < 10; ++i){
        freq_end_dig[i] += freq_end_dig[i - 1]; // The prefix sum of the original array
    }

    int arr_sorted[n];
    int cur_index = 0;
    for(int i = n - 1; i >= 0; --i){
        arr_sorted[freq_end_dig[(arr[i] / pow10) % 10] - 1] = arr[i]; //  -1 because arrays are 0 indexed.
        freq_end_dig[(arr[i] / pow10) % 10]--;

    }

    for(int i = 0; i < n; ++i){
        arr[i] = arr_sorted[i]; // Copying the sorted array to the original array
    }
}



void radixSort(int arr[], int n, int max_element){
    //Basically we have to sort the array based on the ith digit from the end 
    for(int pow10 = 1; pow10 <= max_element && pow10 <= INT_MAX; pow10 *= 10){
        countSort(arr, n, pow10);   // Counting sort has to be called for all exponents upto max element
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


    // Printing the sorted array
    for(int i = 0; i < n; ++i){
        cout << arr[i] << ' ';
    }
}