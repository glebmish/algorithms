// https://www.interviewbit.com/problems/palindrome-partitioning/

bool isPalindrom(string &A, int begin, int end) {
    for (int i = 0; i < (end - begin) / 2; ++i) {
        if (A[begin + i] != A[end - 1 - i]) {
            return false;
        }
    }
    return true;
}

void generatePartitions(string &A, int index, vector<string> &current,
                        vector<vector<string>> &result) {
    // cout << "I'm at " << index << endl;
    if (index >= A.size()) {
        result.push_back(current);
        return;
    }
    for (int i = index + 1; i <= A.size(); ++i) {
        // cout << "Checking " << string(A.begin() + index, A.begin() + i) << endl;
        if (isPalindrom(A, index, i)) {
            // cout << string(A.begin() + index, A.begin() + i) << " is pal" << endl;
            current.push_back(string(A.begin() + index, A.begin() + i));
            generatePartitions(A, i, current, result);
            current.pop_back();
        }
    }
}

bool cmp(const vector<string> &a, const vector<string> &b) {
    for (int i = 0; i < min(a.size(), b.size()); ++i) {
        if (a[i].size() != b[i].size()) {
            return a[i].size() < b[i].size();
        }
    }

    return (a.size() <= b.size());
}

vector<vector<string> > Solution::partition(string A) {
    vector<vector<string>> result;
    vector<string> current;
    generatePartitions(A, 0, current, result);
    sort(result.begin(), result.end(), cmp);
    return result;
}
