#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pasture {
    long long x1, y1, x2, y2;
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<Pasture> pastures(n);
    long long right = 0;

    for (int i = 0; i < n; i++) {
        cin >> pastures[i].x1
            >> pastures[i].y1
            >> pastures[i].x2
            >> pastures[i].y2;

        right = max(right, max(pastures[i].x2, pastures[i].y2));
    }

    long long left = 0;

    while (left < right) {
        long long mid = left + (right - left) / 2;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (pastures[i].x2 <= mid && pastures[i].y2 <= mid) {
                count++;
            }
        }

        if (count >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;

    return 0;
}