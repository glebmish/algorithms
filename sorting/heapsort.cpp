#include <iostream>
#include <vector>
using namespace std;

// O(n*log(n)) average, worst and best
// in-place
// not stable

void sift_down(vector<int>& heap, int n, int i) {
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

void build_heap(vector<int>& heap, int n) {
    for (int i = n / 2; i >= 0; --i)
        sift_down(heap, n, i);
}

void heap_sort(vector<int>& arr) {
    build_heap(arr, arr.size());

    for (int i = arr.size() - 1; i > 0; --i) {
        swap(arr[i], arr[0]);
        sift_down(arr, i, 0);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    heap_sort(arr);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}