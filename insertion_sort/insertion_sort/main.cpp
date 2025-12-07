//
//  main.cpp
//  insertion_sort
//
//  Created by Nestor Dzadzamia on 10.09.25.
//

#include <iostream>
using namespace std;

void increasingInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
       
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void decreasingInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}


int main(int argc, const char * argv[]) {
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5; // only sort first 3 elements
    
    
    // increasingInsertionSort(arr, n);
    decreasingInsertionSort(arr, n);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    return 0;
}


