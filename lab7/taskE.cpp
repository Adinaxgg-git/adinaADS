#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> ans(n);

    int l = 0, r = n - 1;

    for (int k = n - 1; k >= 0; k--) {
        long long left = 1LL * a[l] * a[l];
        long long right = 1LL * a[r] * a[r];

        if (left > right) {
            ans[k] = left;
            l++;
        } else {
            ans[k] = right;
            r--;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i];
        if (i < n - 1) cout << ' ';
    }

    cout << '\n';

    return 0;
}