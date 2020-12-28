#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == x)
            return mid;
        if (arr[mid] > x) {
            return binarySearch(arr, left, mid-1, x);
        }
        return binarySearch(arr, mid+1, right, x);
    }
    // if the element is not found
    return -1;
}

int exponentialSearch(int arr[], int n, int x) {
    // check if first element is the element we are searching for
    if(arr[0] == x)
        return 0;
    
    // find range where the element is present in the sorted array
    int i = 1;
    for(i *= 2; i < n && arr[i] <= x; i *= 2);
    
    // perform binary search in the identified range
    return binarySearch(arr, i/2, i, x);
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 100;
    
    int element = exponentialSearch(arr, n-1, x);
    if (element == -1)
        cout << "Element is not found" <<endl;
    else
        cout << "Element is found at location " << element << endl;
    return 0;
}