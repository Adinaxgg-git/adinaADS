#include <iostream>
using namespace std;

int main() {
    string password, s;
    int k;

    cin >> password >> k;
    cin >> s;

    int count = 0;
    int pos = 0;

    while (s.find(password, pos) != -1) {
        count++;
        pos = s.find(password, pos) + password.length();
    }

    if (count >= k) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}