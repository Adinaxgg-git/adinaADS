#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int count[26] = {0};

    for (int i = 0; i < s.length(); i++) {
        count[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < count[i]; j++) {
            cout << char('a' + i);
        }
    }

    cout << '\n';

    return 0;
}