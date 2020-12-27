/**
 * Average case version of linear search algorithm
 */

#include <iostream>
using namespace std;;

int search(int arr[], int n, int x) {

    int left = 0;
    int right = n - 1;
    
    // if found return left or right
    for (; left <= right; ) {
        if(arr[left] == x) {
            return left;
        }

        if(arr[right] == x) {
            return right;
        }
        left++;
        right--;
    }

    // if not found return -1
    return -1;
}

// driver code
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int x = 4;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << x << " is present at the index " << search(arr, n, x) << endl;
    return 0;
}