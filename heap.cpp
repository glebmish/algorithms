#include <iostream>
using namespace std;

void sift_up(int *heap, int n, int i) {
    if (i == 0)
        return;

    if (heap[(i - 1) / 2] < heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        sift_up(heap, n, (i - 1) / 2);
    }
}

void sift_down(int *heap, int n, int i) {
    int largest = i;

    if (i * 2 + 1 < n && heap[i * 2 + 1] > heap[largest])
        largest = i * 2 + 1;
    if (i * 2 + 2 < n && heap[i * 2 + 2] > heap[largest])
        largest = i * 2 + 2;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        sift_down(heap, n, largest);
    }
}

void build_heap(int *heap, int n) {
    for (int i = n / 2; i >= 0; --i)
        sift_down(heap, n, i);
}

int get_min(int *heap, int n) {
    if (n == 0)
        return -1;

    return heap[0];
}

void pop(int *heap, int n) {
    swap(heap[0], heap[n - 1]);
    sift_down(heap, n - 1, 0);
}

void add(int *heap, int n, int val) {
    heap[n] = val;
    sift_up(heap, n + 1, n);
}

int main() {
    int n;
    cin >> n;

    int heap[100], hsize = n;
    for (int i = 0; i < n; ++i)
        cin >> heap[i];

    build_heap(heap, hsize);

    while (true) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int val;
            cin >> val;
            add(heap, hsize, val);
            hsize++;
        } else if (cmd == "pop") {
            pop(heap, hsize);
            hsize--;
        } else if (cmd == "get") {
            cout << get_min(heap, n) << endl;
        } else if (cmd == "print") {
            for (int i = 0; i < hsize; ++i)
                cout << heap[i] << " ";
            cout << endl;
        }
    }
}