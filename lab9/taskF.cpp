#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, p;
    if (!(cin >> s >> p)) return 0;

    int n = s.length();
    int m = p.length();

    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) {
        int j = pi[i - 1];
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            j++;
        pi[i] = j;
    }

    vector<int> ans;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j])
            j = pi[j - 1];
        if (s[i] == p[j])
            j++;
        if (j == m) {
            ans.push_back(i - m + 2);
            j = pi[j - 1];
        }
    }

    cout << ans.size() << "\n";
    for (size_t i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i + 1 == ans.size() ? "" : " ");
    }
    cout << "\n";

    return 0;
}