#include <iostream>
using namespace std;

// O(n*log(n)) average, worst and best
// O(n) additional memory
// stable (can be modified to not stable)
// not in-place

void merge(int *begin, int *m, int *end) {
    int left_size = m - begin,
        right_size = end - m;

    int *left_arr = new int[left_size],
        *right_arr = new int[right_size];

    for (int i = 0; i < left_size; ++i)
        left_arr[i] = begin[i];

    for (int i = 0; i < right_size; ++i)
        right_arr[i] = m[i];

    int left = 0,
        right = 0,
        to = 0;

    while (left < left_size && right < right_size) {
        if (left_arr[left] <= right_arr[right])
            begin[to++] = left_arr[left++];
        else
            begin[to++] = right_arr[right++];
    }

    while (left < left_size)
        begin[to++] = left_arr[left++];

    while (right < right_size)
        begin[to++] = right_arr[right++];

    delete[] left_arr;
    delete[] right_arr;
}

void merge_sort(int *begin, int *end) {
    if (end - begin < 2)
        return;

    int *m = begin + (end - begin) / 2;

    merge_sort(begin, m);
    merge_sort(m, end);

    merge(begin, m, end);
}

int main() {
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    merge_sort(arr, arr + n);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    return 0;
}