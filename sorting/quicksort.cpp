#include <iostream>
#include <vector>
using namespace std;

// O(n*log(n)) average
// O(n^2) worst
// O(n*log(n)) best
// to avoid qs-killers choose pivot randomly
// in-place
// not stable

void quick_sort(vector<int>::iterator begin, vector<int>::iterator end) {
    if (end - begin < 2)
        return;

    auto pivot = begin;
    auto i = begin + 1, j = end - 1;
    while (i <= j) {
        while (i <= j && *i <= *pivot) {
            ++i;
        }
        while (i <= j  && *j > *pivot) {
            --j;
        }

        if (i < j)
            swap(*i, *j);
    }

    swap(*pivot, *(i - 1));

    quick_sort(begin, i - 1);
    quick_sort(i, end);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    quick_sort(arr.begin(), arr.end());

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}