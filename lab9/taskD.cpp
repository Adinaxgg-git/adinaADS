#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n;

    vector<string> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }

    int mx = 0;

    for (int i = 0; i < n; i++) {
        string t = a[i];

        for (int j = 0; j < t.length(); j++) {
            t[j] = tolower(t[j]);
        }

        int len = min(s.length(), t.length());

        for (int j = 1; j <= len; j++) {
            if (s.substr(s.length() - j) == t.substr(0, j)) {
                mx = max(mx, j);
            }
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        string t = a[i];

        for (int j = 0; j < t.length(); j++) {
            t[j] = tolower(t[j]);
        }

        if (mx > 0 && s.substr(s.length() - mx) == t.substr(0, mx)) {
            count++;
        }
    }

    cout << count << endl;

    for (int i = 0; i < n; i++) {
        string t = a[i];

        for (int j = 0; j < t.length(); j++) {
            t[j] = tolower(t[j]);
        }

        if (mx > 0 && s.substr(s.length() - mx) == t.substr(0, mx)) {
            cout << a[i] << endl;
        }
    }

    return 0;
}