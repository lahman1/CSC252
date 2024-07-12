#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to merge two halves of the array into one
void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int* leftArray = new int[n1];
    int* rightArray = new int[n2];

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; ++i)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArray[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if there are any
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if there are any
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    // Free up memory
    delete[] leftArray;
    delete[] rightArray;
}

// Recursive merge sort function
void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to check if the array is non-strictly increasing
bool is_increasing(int* values, int size) {
    for (int i = 0; i < size - 1; ++i) {
        if (values[i] > values[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    const int size = 100;
    int arr[size];

    // Seed the random number generator
    std::srand(std::time(0));

    // Generate an array of 100 random integer values
    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % 1000; // Random values between 0 and 999
    }

    // Check if the array is non-strictly increasing
    std::cout << "Array is initially increasing: " << (is_increasing(arr, size) ? "true" : "false") << std::endl;

    // Sort the array using merge sort
    mergeSort(arr, 0, size - 1);

    // Check again if the array is non-strictly increasing
    std::cout << "Array is increasing after sorting: " << (is_increasing(arr, size) ? "true" : "false") << std::endl;

    return 0;
}
