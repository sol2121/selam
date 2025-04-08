#include <iostream>
using namespace std;

void merge(int* arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;    

    int* leftArray[n1];
    int* rightArray[n2];

    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];
    int i = 0;
    int j = 0; 
    int k = left; 

    while (i < n1 && j < n2) {
        if (*leftArray[i] <= *rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void pointerMergeSort(int* arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; 
        pointerMergeSort(arr, left, mid);
        pointerMergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int values[] = {5, 2, 4, 6, 1, 3};
    const int n = sizeof(values) / sizeof(values[0]);
    
    int* ptrArray[n]; 
    for (int i = 0; i < n; i++) {
        ptrArray[i] = &values[i]; 
    }

    pointerMergeSort(ptrArray, 0, n - 1);

    cout << "Sorted values: ";
    for (int i = 0; i < n; i++) {
        cout << *ptrArray[i] << " "; 
    }
    cout << endl;

    return 0;
}
#include <iostream>
using namespace std;

void swap(int** a, int** b) {
    int* temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr[], int low, int high) {
    int* pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j < high; j++) {
        if (*arr[j] <= *pivot) {
            i++; 
            swap(&arr[i], &arr[j]); 
        }
    }
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}


void pointerQuickSort(int* arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        pointerQuickSort(arr, low, pi - 1);
        pointerQuickSort(arr, pi + 1, high);
    }
}

int main() {
    int values[] = {5, 2, 4, 6, 1, 3};
    const int n = sizeof(values) / sizeof(values[0]);
    
    int* ptrArray[n]; 
    for (int i = 0; i < n; i++) {
        ptrArray[i] = &values[i]; 
    }
    
    pointerQuickSort(ptrArray, 0, n - 1);

    cout << "Sorted values: ";
    for (int i = 0; i < n; i++) {
        cout << *ptrArray[i] << " "; 
    }
    cout << endl;

    return 0;
}
#include <iostream>
using namespace std;

void pointerSelectionSort(int* arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int* minPtr = arr[i];
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (*arr[j] < *minPtr) {
                minPtr = arr[j];
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int* temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int values[] = {5, 2, 4,11,10,6, 1, 3};
    const int n = sizeof(values) / sizeof(values[0]);
    
    int* ptrArray[n]; 
    for (int i = 0; i < n; i++) {
        ptrArray[i] = &values[i]; 
    }

    pointerSelectionSort(ptrArray, n);
    cout << "Sorted values: ";
    for (int i = 0; i < n; i++) {
        cout << *ptrArray[i] << " "; 
    }
    cout << endl;

    return 0;
}
#include <iostream>
using namespace std;

void pointerBubbleSort(int* arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*arr[j] > *arr[j + 1]) {
                int* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
         }
        }
}

int main() {
    int values[] = {5, 2, 4, 6, 1, 3};
    const int n = sizeof(values) / sizeof(values[0]);
    
    int* ptrArray[n];
    for (int i = 0; i < n; i++) {
        ptrArray[i] = &values[i];
    }
    pointerBubbleSort(ptrArray, n);
    cout << "Sorted values: ";
    for (int i = 0; i < n; i++) {
        cout << *ptrArray[i] << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
using namespace std;

void pointerInsertionSort(int* arr[], int n) {
    for (int i = 1; i < n; i++) {
        int* key = arr[i];  
        int j = i - 1;
        while (j >= 0 && *arr[j] > *key) {
            arr[j + 1] = arr[j];  
            j--;
        }
        arr[j + 1] = key;  
    }
}

int main() {
    int values[] = {5, 2, 4, 6, 1, 3};
    const int n = sizeof(values) / sizeof(values[0]);
    
    int* ptrArray[n];
    for (int i = 0; i < n; i++) {
        ptrArray[i] = &values[i];
    }

    // Sort the pointer array
    pointerInsertionSort(ptrArray, n);

    // Output sorted values (original array remains unchanged)
    cout << "Sorted values: ";
    for (int i = 0; i < n; i++) {
        cout << *ptrArray[i] << " ";
    }
    cout << endl;

    // Original array is still intact
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << values[i] << " ";
    }
    cout << endl;

    return 0;
}