#include <iostream>
using namespace std;

// O(n*log(n)) average
// O(n^2) worst
// O(n*log(n)) best
// to avoid qs-killers choose pivot randomly
// in-place
// not stable

void quick_sort(int *begin, int *end) {
    if (end - begin < 2)
        return;

    int *pivot = begin;
    int *i = begin + 1, *j = end - 1;
    while (i <= j) {
        while (i <= j && *i <= *pivot)
            ++i;
        while (i <= j  && *j > *pivot)
            --j;

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

    int arr[100];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    quick_sort(arr, arr + n);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    return 0;
}