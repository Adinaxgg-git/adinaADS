#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void transformToGreaterSumTree(TreeNode* root, long long &running_sum) {
    if (root == nullptr) {
        return;
    }
    
    transformToGreaterSumTree(root->right, running_sum);
    
    running_sum += root->val;
    root->val = running_sum;
    
    transformToGreaterSumTree(root->left, running_sum);
}

void printIncreasingOrder(TreeNode* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    printIncreasingOrder(root->right, result);
    result.push_back(root->val);
    printIncreasingOrder(root->left, result);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    TreeNode* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    long long running_sum = 0;
    transformToGreaterSumTree(root, running_sum);

    vector<int> result;
    printIncreasingOrder(root, result);

    for (int i = 0; i < n; ++i) {
        cout << result[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}