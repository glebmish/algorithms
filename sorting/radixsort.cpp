#include <iostream>
#include <string>
using namespace std;

// O(n) average, worst and best
// in-place
// stable
// suitable only if max value is rather small

void count_sort(string *begin, string *end, int pos) {
    int count[256];
    for (int i = 0; i < 256; ++i)
        count[i] = 0;

    for (string *i = begin; i != end; ++i)
        count[i[0][pos]]++;
    for (int i = 1; i < 256; ++i)
        count[i] += count[i - 1];

    string *result = new string[end - begin];

    // order is what makes countsort stable
    for (string *i = end - 1; i >= begin; --i) {
        result[count[i[0][pos]] - 1] = *i;
        count[i[0][pos]]--;
    }

    for (string *i = begin, *j = result; i < end; ++i, ++j)
        *i = *j;

    delete[] result;
}

// O(k*n) average, worst and best
// in-place
// stable
// suitable only if max value is rather small

void radix_sort(string *begin, string *end, int len) {
    for (int i = len - 1; i >= 0; --i)
        count_sort(begin, end, i);
}

int main() {
    int n;
    cin >> n;

    string arr[100];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    radix_sort(arr, arr + n, 3);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    return 0;
}