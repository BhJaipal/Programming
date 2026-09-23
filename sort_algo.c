#include "sort_algo.h"

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    // output array
    int output[n];
    int i, count[10] = { 0 };

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

int radix_sort(int *arr, int n, read_arr_fn_t read_on_iter,
               read_on_swap_fn_t read_after_swap)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
        if (read_on_iter)
            read_on_iter(arr, n);
        if (read_after_swap)
            read_after_swap(arr, n, 0, 0);
    }
    return 0;
}

// @read_on_iter can be NULL, allows use to check array after each iteration
int selection_sort(int *arr, int n, read_arr_fn_t read_on_iter,
                   read_on_swap_fn_t read_after_swap)
{
    int d = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_i = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_i]) {
                min_i = j;
            }
        }

        if (i != min_i) {
            d++;
            int x = arr[i];
            arr[i] = arr[min_i];
            arr[min_i] = x;
            if (read_after_swap)
                read_after_swap(arr, n, i, min_i);
        }
        if (read_on_iter)
            read_on_iter(arr, n);
    }
    return d;
}

// @read_on_iter can be NULL, allows use to check array after each iteration
int insertion_sort(int arr[], int n, read_arr_fn_t read_on_iter,
                   read_on_swap_fn_t read_after_swap)
{
    int rep = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j;

        for (j = i - 1; j >= 0 && key < arr[j]; j--) {
            arr[j + 1] = arr[j];
            rep++;
        }

        arr[j + 1] = key;
        if (read_after_swap)
            read_after_swap(arr, n, j + 1, i);
        if (read_on_iter)
            read_on_iter(arr, n);
    }
    return rep;
}

// @read_on_iter can be NULL, allows use to check array after each iteration
int bubble_sort(int *arr, int n, read_arr_fn_t read_on_iter,
                read_on_swap_fn_t read_after_swap)
{
    int d = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int x = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = x;
                d++;
                if (read_after_swap)
                    read_after_swap(arr, n, j + 1, j);
            }
            if (read_on_iter)
                read_on_iter(arr, n);
        }
    }
    return d;
}

// @read_on_iter can be NULL, allows use to check array after each iteration
int quick_sort(int *arr, int start, int end, int n, read_arr_fn_t read_on_iter,
               read_on_swap_fn_t read_after_swap)
{
    if (start >= end)
        return 0;
    int pivot = arr[end - 1];

    int found = start - 1;
    int d = 0;

    for (int i = start; i < end; i++) {
        if (arr[i] < pivot) {
            found++;
            int x = arr[found];
            arr[found] = arr[i];
            arr[i] = x;
            d++;
            if (read_after_swap)
                read_after_swap(arr, n, i, found);
        }
        if (read_on_iter)
            read_on_iter(arr, n);
    }

    if (end - 1 != found + 1) {
        int x = arr[end - 1];
        arr[end - 1] = arr[found + 1];
        arr[found + 1] = x;
        if (read_after_swap)
            read_after_swap(arr, n, end - 1, found + 1);
    }
    if (read_on_iter)
        read_on_iter(arr, n);

    d += quick_sort(arr, start, found + 1, n, read_on_iter, read_after_swap);
    d += quick_sort(arr, found + 2, end, n, read_on_iter, read_after_swap);
    return d;
}
void merge(int *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    int L[n1], R[n2];

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
int merge_sort(int *arr, int left, int right, int n, read_arr_fn_t read_on_iter,
               read_on_swap_fn_t read_after_swap)
{
    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid, n, read_on_iter, read_after_swap);
    merge_sort(arr, mid + 1, right, n, read_on_iter, read_after_swap);
    merge(arr, left, mid, right);
    if (read_on_iter)
        read_on_iter(arr, n);
    if (read_after_swap)
        read_after_swap(arr, n, right, left);
    return 0;
}
