#include <iostream>
using namespace std;

// O(n*log(n)) average, worst and best
// in-place
// not stable

void sift_down(int *heap, int n, int i) {
    int largest = i;
    if (i * 2 + 1 < n && heap[i * 2 + 1] > heap[largest])
        largest = i * 2 + 1;
    if (i * 2 + 2 < n && heap[i * 2 + 2] > heap[largest])
        largest = i * 2 + 2;
    if (largest != i) {
        swap(heap[largest], heap[i]);
        sift_down(heap, n, largest);
    }
}

void build_heap(int *heap, int n) {
    for (int i = n / 2; i >= 0; --i)
        sift_down(heap, n, i);
}

void heap_sort(int *begin, int *end) {
    build_heap(begin, end - begin);

    for (int i = end - begin - 1; i > 0; --i) {
        swap(begin[i], begin[0]);
        sift_down(begin, i, 0);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    heap_sort(arr, arr + n);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    return 0;
}