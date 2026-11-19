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

Node* insertNode(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->value)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);

    return root;
}

void findKth(Node* root, int k, int& count, int& answer) {
    if (root == nullptr || answer != -1)
        return;

    findKth(root->left, k, count, answer);

    count++;

    if (count == k) {
        answer = root->value;
        return;
    }

    findKth(root->right, k, count, answer);
}

int main() {
    int n, k;
    cin >> n >> k;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insertNode(root, x);
    }

    if (k < 1 || k > n) {
        cout << -1;
        return 0;
    }

    int count = 0;
    int answer = -1;

    findKth(root, k, count, answer);

    cout << answer;

    return 0;
}