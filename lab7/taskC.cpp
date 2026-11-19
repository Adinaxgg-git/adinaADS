#include <iostream>
#include <vector>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    long long sumA = 0, sumB = 0;

    for (int x : a) sumA += x;
    for (int x : b) sumB += x;

    if (sumA != sumB) return sumA > sumB;

    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] != b[i]) return a[i] < b[i];
    }

    return false;
}

void mergeSort(vector<vector<int>>& a, int l, int r) {
    if (l >= r) return;

    int m = l + (r - l) / 2;

    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);

    vector<vector<int>> temp;
    int i = l, j = m + 1;

    while (i <= m && j <= r) {
        if (cmp(a[i], a[j])) {
            temp.push_back(a[i++]);
        } else {
            temp.push_back(a[j++]);
        }
    }

    while (i <= m) temp.push_back(a[i++]);
    while (j <= r) temp.push_back(a[j++]);

    for (int k = 0; k < (int)temp.size(); k++) {
        a[l + k] = temp[k];
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    if (n > 0) mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0) cout << ' ';
            cout << a[i][j];
        }
        cout << '\n';
    }

    return 0;
}