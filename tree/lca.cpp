// https://www.interviewbit.com/problems/least-common-ancestor/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 vector<int> findPath(TreeNode* A, int B) {
    if (A == nullptr) {
        return vector<int>();
    }
    if (A->val == B) {
        return vector<int>(1, B);
    }
    
    vector<int> path = findPath(A->left, B);
    if (path.empty()) {
        path = findPath(A->right, B);
    }
    
    if (!path.empty()) {
        path.push_back(A->val);
    }
    
    return path;
 }
 
int Solution::lca(TreeNode* A, int B, int C) {
    vector<int> pathToB = findPath(A, B);
    vector<int> pathToC = findPath(A, C);
    
    if (pathToB.empty() || pathToC.empty()) {
        return -1;
    } else {
        reverse(pathToB.begin(), pathToB.end());
        reverse(pathToC.begin(), pathToC.end());
        
        int ca = pathToB[0];
        for (int i = 1; i < min(pathToB.size(), pathToC.size()); ++i) {
            if (pathToB[i] == pathToC[i]) {
                ca = pathToB[i];
            } else {
                break;
            }
        }
        return ca;
    }
}

