#include <iostream>
#include <string>
#include <vector>
using namespace std;

// O(n) average, worst and best
// in-place
// stable
// suitable only if max value is rather small

void count_sort(vector<string>& arr, int pos) {
    vector<int> count(256, 0);

    for (int i = 0; i < arr.size(); ++i) {
        count[arr[i][pos]]++;
    }
    for (int i = 1; i < 256; ++i) {
        count[i] += count[i - 1];
    }

    vector<string> result(arr.size());

    // order is what makes countsort stable
    for (int i = arr.size() - 1; i >= 0; --i) {
        int index = count[arr[i][pos]] - 1;
        result[index] = arr[i];
        count[arr[i][pos]]--;
    }

    for (int i = 0, j = 0; j < arr.size(); ++i, ++j) {
        arr[i] = result[j];
    }
}

// O(k*n) average, worst and best
// in-place
// stable
// suitable only if max value is rather small

void radix_sort(vector<string>& arr, int len) {
    for (int i = len - 1; i >= 0; --i) {
        count_sort(arr, i);
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    radix_sort(arr, 3);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}