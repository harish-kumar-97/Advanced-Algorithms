/**
 * This is an example program to worst case with linear search
 *
 * Worst case: when the element to be searched (x in the above code) is not present in the array
 * Average case: In average case analysis, we take all possible inputs and calculate computing time 
 *               for all of the inputs. Sum all the calculated values and divide the sum by total number of inputs.(Θ(n)).
 * Best case: O(1). The best case occurs when the element occurs at the first location.
 */

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/**
 * linearly search x in arr[]. If x is present then return 
 * the index otherwise return -1. 
 */
int search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

/* Driver code */
int main()
{
    int arr[] = {1, 10, 30, 15};
    int x = 30;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << x << " is present at the index " << search(arr, n, x) << endl;
    return 0;
}