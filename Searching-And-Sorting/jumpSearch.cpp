/**
 * A CPP Program to demonstrate the Jump Search algorithm: The basic idea is to 
 * check fewer elements (than linear search) by jumping ahead by fixed steps or 
 * skipping some elements in place of searching all elements.
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int jumpSearch(int arr[], int x, int n) {
    int m = sqrt(n);

    // find the block where x is present
    int prev = 0;
    while(arr[m] < x) {
        prev = m;
        m += m;
        if(arr[m] == x)
            return m;
    }
    
    // linear search on the subset
    while(arr[prev] < x) {
        prev++;
        if(arr[prev] == x)
            return prev;
    }

    // takes care of the first element
    if(arr[prev] == x)
        return prev;

    return -1;
}

int main() {
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 };
    int x = 610;
    int n = sizeof(arr) / sizeof(arr[0]); 
    
    int index = jumpSearch(arr, x, n);

    cout << "Number " << x << " is at index " << index << endl;
    return 0;
}