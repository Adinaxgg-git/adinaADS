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
        else if (value > current->value) {
            if (current->right == nullptr) {
                current->right = new Node(value);
                return;
            }

            current = current->right;
        }
        else {
            return;
        }
    }
}

int diameter(Node* root, int& answer) {
    if (root == nullptr)
        return 0;

    int leftHeight = diameter(root->left, answer);
    int rightHeight = diameter(root->right, answer);

    int currentDiameter = leftHeight + rightHeight + 1;

    answer = max(answer, currentDiameter);

    return max(leftHeight, rightHeight) + 1;
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

    int answer = 0;

    diameter(root, answer);

    cout << answer << '\n';

    return 0;
}