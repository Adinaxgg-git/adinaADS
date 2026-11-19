#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<double> ropes(n);
    double maxLength = 0;

    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
        if (ropes[i] > maxLength) {
            maxLength = ropes[i];
        }
    }

    double left = 0;
    double right = maxLength;

    for (int i = 0; i < 100; i++) {
        double mid = (left + right) / 2;
        int pieces = 0;

        for (int j = 0; j < n; j++) {
            pieces += (int)(ropes[j] / mid);
        }

        if (pieces >= k) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << fixed << setprecision(9) << left << endl;

    return 0;
}