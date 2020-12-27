 /**
  * A simple program to demonstrate the Binary Search algorithm
  */

 #include <iostream>
 using namespace std;

int binarySearchRecursive(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == x)
            return mid;
        if (arr[mid] > x) {
            return binarySearchRecursive(arr, left, mid-1, x);
        }
        return binarySearchRecursive(arr, mid+1, right, x);
    }
    // if the element is not found
    return -1;
}

int binarySearchIterative(int arr[], int left, int right, int x) {
    int mid;    
    while(left <= right) {
        mid = left + (right - left)/2;

        if(arr[mid] == x)
            return mid;
        if(arr[mid] > x) {
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    // if the element is not found
    return -1;
}

// driver code
 int main() {
     int arr[] = {1, 2, 3, 4, 5};
     int x = 3;
     cout << x << " is at location " << binarySearchIterative(arr, 0, sizeof(arr)/sizeof(arr[0]), x);
 }