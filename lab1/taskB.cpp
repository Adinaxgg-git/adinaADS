#include <iostream>
using namespace std;

int main() {
    long long a, n, m;
    cin >> a >> n >> m;

    long long result = 1 % m;
    a = a % m;

    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * a) % m;
        }

        a = (a * a) % m;
        n = n / 2;
    }

    cout << result;

    return 0;
}