int bin_s(vector<int>& vec, int begin, int end, int val) {
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

int main() {
    vector<int> vec = {1, 2, 2, 2, 3, 4, 5};
    cout << bin_s(vec, 0, vec.size(), 1);
    cout << bin_s(vec, 0, vec.size(), 2);
    cout << bin_s(vec, 0, vec.size(), 3);
    cout << bin_s(vec, 0, vec.size(), 5);
}
