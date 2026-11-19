#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int left = 0;
    int right = 0;
};

int main() {
    int n;
    cin >> n;

    vector<Node> tree(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int parent, child, side;
        cin >> parent >> child >> side;

        if (side == 0) {
            tree[parent].left = child;
        }
        else {
            tree[parent].right = child;
        }
    }

    queue<int> q;
    q.push(1);

    int answer = 0;

    while (!q.empty()) {
        int width = q.size();

        answer = max(answer, width);

        for (int i = 0; i < width; i++) {
            int current = q.front();
            q.pop();

            if (tree[current].left != 0) {
                q.push(tree[current].left);
            }

            if (tree[current].right != 0) {
                q.push(tree[current].right);
            }
        }
    }

    cout << answer << '\n';

    return 0;
}