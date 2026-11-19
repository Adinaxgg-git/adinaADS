#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<char> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    char x;
    cin >> x;

    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            cout << a[i] << '\n';
            return 0;
        }
    }

    cout << a[0] << '\n';

    return 0;
}