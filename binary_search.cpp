#include <vector>
#include <iostream>
using namespace std;

int bin_s_upper_bound(vector<int>& vec, int begin, int end, int val) {
    int l = begin - 1, r = end - 1;

    while (l < r) {
        int m = l + (r - l + 1) / 2;

        if (vec[m] > val) {
            r = m - 1;
        } else {
            l = m;
        }
    }

    if (vec[l] == val) {
        return l;
    } else {
        return -1;
    }
}

int bin_s_lower_bound(vector<int>& vec, int begin, int end, int val) {
    int l = begin, r = end;

    while (l < r) {
        int m = l + (r - l) / 2;

        if (vec[m] >= val) {
            r = m;
        } else {
            l = m + 1;
        }

    }

    if (vec[l] == val) {
        return l;
    } else {
        return -1;
    }
}

int main() {
    vector<int> vec = {1, 2, 2, 2, 3, 4, 5};
    cout << bin_s_upper_bound(vec, 0, vec.size(), 1) << endl;
    cout << bin_s_upper_bound(vec, 0, vec.size(), 2) << endl;
    cout << bin_s_lower_bound(vec, 0, vec.size(), 2) << endl;
    cout << bin_s_upper_bound(vec, 0, vec.size(), 3) << endl;
    cout << bin_s_upper_bound(vec, 0, vec.size(), 5) << endl;
}
