#include <iostream>
using namespace std;

void findLargestElements(int arr[], int n) {
    if (n < 3) {
        cout << "Array must have at least three elements" << endl;
        return;
    }

    int largest = INT_MIN, secondLargest = INT_MIN, thirdLargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            thirdLargest = secondLargest;
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] < largest) {
            thirdLargest = secondLargest;
            secondLargest = arr[i];
        } else if (arr[i] > thirdLargest && arr[i] < secondLargest) {
            thirdLargest = arr[i];
        }
    }

    cout << "Largest Element: " << largest << endl;
    if (secondLargest != INT_MIN)
        cout << "Second Largest Element: " << secondLargest << endl;
    else
        cout << "No second largest element found" << endl;

    if (thirdLargest != INT_MIN)
        cout << "Third Largest Element: " << thirdLargest << endl;
    else
        cout << "No third largest element found" << endl;
}

int main() {
    int arr[] = {24, 35, 21, 10, 64, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    findLargestElements(arr, n);

    return 0;
}