// https://www.interviewbit.com/problems/subset/

void generateSubsets(vector<int> &A, int i, vector<int> &current, vector<vector<int>> &result) {
    if (i >= A.size()) {
        result.push_back(current);
        return;
    }

    generateSubsets(A, i + 1, current, result);
    current.push_back(A[i]);
    generateSubsets(A, i + 1, current, result);
    current.pop_back();
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<int> current;
    vector<vector<int>> result;
    generateSubsets(A, 0, current, result);
    sort(result.begin(), result.end());
    return result;
}
