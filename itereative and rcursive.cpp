#include <iostream>
using namespace std;

int binarySearchIterative(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid;  
        }
        if (arr[mid] < target) {
            low = mid + 1;  
        } else {
            high = mid - 1;
        }
    }
    return -1; 
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    
    int result = binarySearchIterative(arr, n, target);
    
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }
    
    return 0;
}
Binary Search - Recursive Approach
In the recursive approach, the function calls itself with a reduced range until it finds the target or the range is exhausted.

Time Complexity: O(log N)
Space Complexity: O(log N) (due to the call stack)

cpp
Copy
#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1;  
    }
    
    int mid = low + (high - low) / 2;
    
    if (arr[mid] == target) {
        return mid;  
    } 
    if (arr[mid] < target) {
        return binarySearchRecursive(arr, mid + 1, high, target);
    } else {
        return binarySearchRecursive(arr, low, mid - 1, target);  
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    
    int result = binarySearchRecursive(arr, 0, n - 1, target);
    
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }
    
    return 0;
}
Comparison of Complexity
Time Complexity:

Both iterative and recursive binary search have a time complexity of O(log N) because the search space is halved at each step.

Space Complexity:

Iterative approach: O(1), as it uses a constant amount of extra space (just a few variables for indices).

Recursive approach: O(log N), because each recursive call adds a new frame to the call stack, and the maximum depth of the recursion is log N.

Summary:
Iterative Approach: More memory-efficient as it does not require additional space for recursion. The loop runs until the target is found or the search space is exhausted.

Recursive Approach: While easier to understand and implement, it uses more memory due to the call stack and may cause a stack overflow for large input sizes.

In practice, the iterative version is generally preferred for problems that can be solved iteratively, as it avoids the overhead of recursion and is more memory-efficient. However, recursion can be more elegant and easier to understand in some cases.