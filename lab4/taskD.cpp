#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    int level;
    Node* left;
    Node* right;

    Node(int v, int l) {
        value = v;
        level = l;
        left = nullptr;
        right = nullptr;
    }
};

void insertNode(Node*& root, int value) {
    if (root == nullptr) {
        root = new Node(value, 0);
        return;
    }

    Node* current = root;
    int level = 0;

    while (true) {
        level++;

        if (value < current->value) {
            if (current->left == nullptr) {
                current->left = new Node(value, level);
                return;
            }

            current = current->left;
        }
        else {
            if (current->right == nullptr) {
                current->right = new Node(value, level);
                return;
            }

            current = current->right;
        }
    }
}

void calculateSums(Node* root, vector<long long>& sums) {
    if (root == nullptr)
        return;

    if (root->level >= sums.size())
        sums.resize(root->level + 1, 0);

    sums[root->level] += root->value;

    calculateSums(root->left, sums);
    calculateSums(root->right, sums);
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertNode(root, x);
    }

    vector<long long> sums;

    calculateSums(root, sums);

    cout << sums.size() << '\n';

    for (long long x : sums) {
        cout << x << " ";
    }

    cout << '\n';

    return 0;
}