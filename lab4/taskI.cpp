#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int v) {
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

void insertNode(Node*& root, int value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }

    Node* current = root;

    while (true) {
        if (value < current->value) {
            if (current->left == nullptr) {
                current->left = new Node(value);
                return;
            }
            current = current->left;
        }
        else {
            if (current->right == nullptr) {
                current->right = new Node(value);
                return;
            }
            current = current->right;
        }
    }
}

int countLeaves(Node* root) {
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
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

    cout << countLeaves(root) << '\n';

    return 0;
}