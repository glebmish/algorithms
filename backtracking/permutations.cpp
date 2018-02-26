// https://www.interviewbit.com/problems/permutations/

void generatePermutations(vector<int> &A, vector<bool> &used,
                          vector<int> &current, vector<vector<int>> &result) {

    if (A.size() == current.size()) {
        result.push_back(current);
    }

    for (int i = 0; i < used.size(); ++i) {
        if (!used[i]) {
            current.push_back(A[i]);
            used[i] = true;
            generatePermutations(A, used, current, result);
            used[i] = false;
            current.pop_back();
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(A.size(), false);

    generatePermutations(A, used, current, result);
    sort(result.begin(), result.end());
    return result;
}
