#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]
        if (arr[high] == arr[low]) {
            if (arr[low] == target) return low;
            break;

        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        
        if (arr[pos] == target) {
            return pos; 
        } else if (arr[pos] < target) {
            low = pos + 1; 
        } else {
            high = pos - 1; 
        }
    }

    return -1; 
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; 
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 13;

    int result = interpolationSearch(arr, size, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}