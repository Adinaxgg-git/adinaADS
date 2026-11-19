#include <iostream>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;

    vector<int> queries(q);

    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    int n, m;
    cin >> n >> m;

    vector<vector<long long>> a(n, vector<long long>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int x : queries) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            int left = 0;
            int right = m - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (a[i][mid] == x) {
                    cout << i << " " << mid << endl;
                    found = true;
                    break;
                }

                if (i % 2 == 0) {
                    // Чётная строка: убывает
                    if (a[i][mid] > x) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                } else {
                    // Нечётная строка: возрастает
                    if (a[i][mid] < x) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }

            if (found) {
                break;
            }
        }

        if (!found) {
            cout << -1 << endl;
        }
    }

    return 0;
}