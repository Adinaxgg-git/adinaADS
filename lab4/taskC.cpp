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

Node* findNode(Node* root, int value) {
    Node* current = root;

    while (current != nullptr) {
        if (current->value == value) {
            return current;
        }

        if (value < current->value)
            current = current->left;
        else
            current = current->right;
    }

    return nullptr;
}

void preorder(Node* root) {
    if (root == nullptr)
        return;

    cout << root->value << " ";

    preorder(root->left);
    preorder(root->right);
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

    int target;
    cin >> target;

    Node* node = findNode(root, target);

    preorder(node);

    return 0;
}