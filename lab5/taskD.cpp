#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        pq.push(x);
    }

    int count = 0;

    while (pq.size() > 1 && pq.top() < k) {
        long long a = pq.top();
        pq.pop();

        long long b = pq.top();
        pq.pop();

        pq.push(a + 2 * b);
        count++;
    }

    if (!pq.empty() && pq.top() >= k) {
        cout << count;
    } else {
        cout << -1;
    }

    return 0;
}
