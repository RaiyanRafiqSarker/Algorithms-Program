#include <iostream>
using namespace std;

void countingSort(int arr[], int n) {
    if (n <= 1)
        return;


    int max_element = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }


    int* count = new int[max_element + 1]();


    for (int i = 0; i < n; ++i) {
        ++count[arr[i]];
    }


    for (int i = 1; i <= max_element; ++i) {
        count[i] += count[i - 1];
    }


    int* output = new int[n];


    for (int i = n - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }


    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }

    delete[] count;
    delete[] output;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

   cout << "Original array: ";
    printArray(arr, n);

    countingSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
