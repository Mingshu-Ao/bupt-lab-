#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100 // Define the maximum size of the array

// Variables to count the number of comparisons and movements
long long comparisonCount, movementCount;

// Utility function: Swap two elements
void swapElements(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    movementCount += 3; // A swap operation counts as 3 movements
}

// 1. Insertion Sort - renamed to performInsertionSort for clarity
// This function implements the insertion sort algorithm.
// It sorts the given array 'arr' of size 'n' in ascending order.
// During the sorting process, it also counts the number of comparisons and movements.
void performInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        movementCount++; // Assigning the value to 'key' counts as 1 movement
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisonCount++;
            arr[j + 1] = arr[j];
            movementCount++;
            j--;
        }
        comparisonCount++; // The comparison in the last round when not entering the while loop
        arr[j + 1] = key;
        movementCount++;
    }
}

// 2. Shell Sort - renamed to performShellSort for clarity
// This function implements the shell sort algorithm.
// Shell sort is an improvement over insertion sort.
// It sorts the array 'arr' of size 'n' and keeps track of comparisons and movements.
void performShellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int key = arr[i];
            movementCount++;
            int j = i;
            while (j >= gap && arr[j - gap] > key) {
                comparisonCount++;
                arr[j] = arr[j - gap];
                movementCount++;
                j -= gap;
            }
            comparisonCount++;
            arr[j] = key;
            movementCount++;
        }
    }
}

// 3. Bubble Sort - renamed to performBubbleSort for clarity
// This function implements the bubble sort algorithm.
// It repeatedly steps through the array 'arr' of size 'n',
// compares adjacent elements and swaps them if they are in the wrong order.
// Counts the number of comparisons and movements during the sorting process.
void performBubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisonCount++;
            if (arr[j] > arr[j + 1]) {
                swapElements(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// 4. Quick Sort - renamed helper function to partitionAndSortQuickly for clarity
// This is the helper function for the quick sort algorithm.
// It partitions the array 'arr' between indices 'low' and 'high'
// and recursively sorts the sub-arrays on either side of the pivot.
// Also counts the relevant comparisons and movements.
void partitionAndSortQuickly(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        movementCount++;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            comparisonCount++;
            if (arr[j] < pivot) {
                i++;
                swapElements(&arr[i], &arr[j]);
            }
        }
        swapElements(&arr[i + 1], &arr[high]);
        partitionAndSortQuickly(arr, low, i);
        partitionAndSortQuickly(arr, i + 2, high);
    }
}

// Renamed main quick sort function to initiateQuickSort for clarity
// This function initiates the quick sort process on the entire array 'arr' of size 'n'.
void initiateQuickSort(int arr[], int n) {
    partitionAndSortQuickly(arr, 0, n - 1);
}

// 5. Selection Sort - renamed to performSelectionSort for clarity
// This function implements the selection sort algorithm.
// It repeatedly finds the minimum element from the unsorted part of the array 'arr' of size 'n'
// and swaps it with the element at the beginning of the unsorted part.
// Counts the comparisons and movements during the sorting operation.
void performSelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisonCount++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swapElements(&arr[i], &arr[minIndex]);
        }
    }
}

// 6. Heap Sort - renamed helper function to maintainHeapProperty for clarity
// This function is a helper function for heap sort.
// It maintains the max heap property for a subtree rooted at index 'i' in the array 'arr' of size 'n'.
// Compares elements and makes swaps if necessary to maintain the heap property.
void maintainHeapProperty(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    comparisonCount++;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    comparisonCount++;
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swapElements(&arr[i], &arr[largest]);
        maintainHeapProperty(arr, n, largest);
    }
}

// Renamed main heap sort function to performHeapSort for clarity
// This function implements the heap sort algorithm.
// It first builds a max heap from the array 'arr' of size 'n'
// and then repeatedly extracts the maximum element and reheapifies the remaining elements.
// Counts the comparisons and movements during the sorting process.
void performHeapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maintainHeapProperty(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swapElements(&arr[0], &arr[i]);
        maintainHeapProperty(arr, i, 0);
    }
}

// 7. Merge Sort - renamed merge function to mergeTwoSubarrays for clarity
// This function merges two sorted subarrays of the array 'arr'.
// The two subarrays are defined by the indices 'l' to'm' and'm + 1' to 'r'.
// It copies elements to temporary arrays, merges them back to the original array,
// and counts the movements and comparisons during the merge process.
void mergeTwoSubarrays(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
        movementCount++;
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
        movementCount++;
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comparisonCount++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
            movementCount++;
        }
        else {
            arr[k++] = R[j++];
            movementCount++;
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
        movementCount++;
    }

    while (j < n2) {
        arr[k++] = R[j++];
        movementCount++;
    }

    free(L);
    free(R);
}

// Renamed merge sort helper function to recursivelyMergeSort for clarity
// This is the helper function for the merge sort algorithm.
// It recursively divides the array 'arr' into smaller subarrays and then merges them back in sorted order.
void recursivelyMergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        recursivelyMergeSort(arr, l, m);
        recursivelyMergeSort(arr, m + 1, r);
        mergeTwoSubarrays(arr, l, m, r);
    }
}

// Renamed main merge sort function to initiateMergeSort for clarity
// This function initiates the merge sort process on the entire array 'arr' of size 'n'.
void initiateMergeSort(int arr[], int n) {
    recursivelyMergeSort(arr, 0, n - 1);
}

// Generate a random array with elements in a certain range.
// The generated array 'arr' will have 'n' elements.
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

// Print the elements of the array 'arr' of size 'n'.
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand((unsigned int)time(NULL));
    int n = 100; // The length of the array
    int arr[MAX_SIZE];
    int temp[MAX_SIZE];

    // An array of pointers to sorting functions.
    // Each pointer points to a different sorting algorithm function.
    void (*sortingAlgorithms[])(int[], int) = {
        performInsertionSort, performShellSort, performBubbleSort, initiateQuickSort,
        performSelectionSort, performHeapSort, initiateMergeSort
    };

    // An array of strings containing the names of the sorting algorithms.
    // Each name corresponds to the sorting algorithm in the'sortingAlgorithms' array.
    const char* algorithmNames[] = {
        "Insertion Sort", "Shell Sort", "Bubble Sort", "Quick Sort",
        "Selection Sort", "Heap Sort", "Merge Sort"
    };

    int numAlgorithms = sizeof(sortingAlgorithms) / sizeof(sortingAlgorithms[0]);

    for (int test = 1; test <= 5; test++) {
        printf("\nTest #%d:\n", test);
        generateRandomArray(arr, n);

        for (int i = 0; i < numAlgorithms; i++) {
            // Reset the counters for comparisons and movements before each sorting algorithm is tested.
            comparisonCount = 0;
            movementCount = 0;

            // Copy the original array to a temporary array for each sorting algorithm test.
            for (int j = 0; j < n; j++) {
                temp[j] = arr[j];
            }

            // Execute the sorting algorithm and print its name.
            printf("%s:\n", algorithmNames[i]);
            sortingAlgorithms[i](temp, n);

            // Output the statistics of comparisons and movements after the sorting is completed.
            printf("Comparisons: %lld, Movements: %lld\n", comparisonCount, movementCount);
        }
    }

    return 0;
}