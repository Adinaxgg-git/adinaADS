#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int q, k;
    cin >> q >> k;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long sum = 0;

    for (int i = 0; i < q; i++) {
        string command;
        cin >> command;

        if (command == "insert") {
            long long x;
            cin >> x;

            pq.push(x);
            sum += x;

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
        } else if (command == "print") {
            cout << sum << '\n';
        }
    }

    return 0;
}