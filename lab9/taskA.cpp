#include <iostream>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    string s = A;
    int count = 1;

    while (s.length() < B.length()) {
        s += A;
        count++;
    }

    if (s.find(B) != -1) {
        cout << count;
        return 0;
    }

    s += A;
    count++;

    if (s.find(B) != -1) {
        cout << count;
    } else {
        cout << -1;
    }

    return 0;
}
