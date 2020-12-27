/**
 * Worst Case implementation of linear search algorithm
 */

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