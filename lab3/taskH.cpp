#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long k;

    cin >> n >> k;

    vector<long long> a(n);
    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        prefix[i + 1] = prefix[i] + a[i];
    }
    int answer = n;
    for (int left = 0; left < n; left++) {

        int l = left;
        int r = n - 1;

        int bestRight = -1;

        while (l <= r) {
            int mid = (l + r) / 2;

            long long sum = prefix[mid + 1] - prefix[left];

            if (sum >= k) {
                                                                                                                                    
                                                                                                                                                
                bestRight = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (bestRight != -1) {
            int length = bestRight - left + 1;
            answer = min(answer, length);
        }
    }

    cout << answer << endl;
    return 0;
}