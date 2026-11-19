#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    string s = b + b;

    int pos = s.find(a);

    if (pos == -1 || pos >= b.length()) {
        cout << -1;
    } else {
        cout << pos;
    }

    return 0;
}