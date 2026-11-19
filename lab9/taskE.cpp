#include <iostream>
#include <string>
#include <vector>
using namespace std;
void solve() {
    string s;
    long long k;
    if (!(cin >> s >> k)) return;

    long long L = s.length();

    vector<int> pi(L, 0);
    for (int i = 1; i < L; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }

    long long overlap = pi[L - 1];
    long long ans = L + (k - 1) * (L - overlap);

    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}