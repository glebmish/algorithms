#include <iostream>
using namespace std;

// O(log(n))
// works on sorted array (or monotonic function)

// upper bound
// comments for lower
int *bin_search_upper(int val, int *begin, int *end) {
    // l = begin - 1, r = end - 1
    int *l = begin, *r = end;
    while (r - l != 1) {
        int *m = l + (r - l) / 2;

        // m >= val
        if (*m > val)
            r = m;
        else
            l = m;
    }

    // r == val
    if (*l == val)
        // return r;
        return l;
    else
        return NULL;
}

int main() {
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    while (true) {
        int val;
        cin >> val;

        int *pos = bin_search_upper(val, arr, arr + n);

        if (pos == NULL)
            cout << "none" << endl;
        else
            cout << pos - arr << endl;
    }
}
