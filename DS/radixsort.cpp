#include <iostream>
#include <vector>

using namespace std;

// Function to get the maximum element from an array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform counting sort based on the digit represented by exp
void countingSort(int arr[], int n, int exp) {
    int output[n]; // Output array
    int count[10] = {0}; // Initialize count array with zeros

    // Store count of occurrences in count[]
    for (int i = 0; i < n; ++i) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to the current digit
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

// Function to perform Radix Sort
void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int max = getMax(arr, n);

    // Perform counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is the current digit number
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:" << endl;
    printArray(arr, n);

    radixSort(arr, n);

    cout << "Sorted array:" << endl;
    printArray(arr, n);

    return 0;
}
