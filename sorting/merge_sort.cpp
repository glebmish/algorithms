#include <iostream>
#include <vector>
using namespace std;

// O(n*log(n)) average, worst and best
// O(n) additional memory
// stable (can be modified to not stable)
// not in-place

void merge(vector<int>::iterator begin, vector<int>::iterator m, vector<int>::iterator end) {
    int left_size = m - begin;
    int right_size = end - m;

    vector<int> left_arr(left_size);
    vector<int> right_arr(right_size);

    for (int i = 0; i < left_size; ++i) {
        left_arr[i] = begin[i];
    }

    for (int i = 0; i < right_size; ++i) {
        right_arr[i] = m[i];
    }

    int left = 0;
    int right = 0;
    int to = 0;

    while (left < left_size && right < right_size) {
        if (left_arr[left] <= right_arr[right]) {
            begin[to] = left_arr[left];
            ++left;
        } else {
            begin[to] = right_arr[right];
            ++right;
        }
        to++;
    }

    while (left < left_size) {
        begin[to] = left_arr[left];
        ++to;
        ++left;
    }

    while (right < right_size) {
        begin[to] = right_arr[right];
        ++to;
        ++right;
    }
}

void merge_sort(vector<int>::iterator begin, vector<int>::iterator end) {
    if (end - begin < 2)
        return;

    auto m = begin + (end - begin) / 2;

    merge_sort(begin, m);
    merge_sort(m, end);

    merge(begin, m, end);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    merge_sort(arr.begin(), arr.end());

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}