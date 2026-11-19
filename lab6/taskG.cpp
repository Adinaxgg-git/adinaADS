#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> oldNames;
    vector<string> newNames;

    for (int i = 0; i < n; i++) {
        string oldName, newName;
        cin >> oldName >> newName;

        bool found = false;

        for (int j = 0; j < newNames.size(); j++) {
            if (newNames[j] == oldName) {
                newNames[j] = newName;
                found = true;
                break;
            }
        }

        if (!found) {
            oldNames.push_back(oldName);
            newNames.push_back(newName);
        }
    }

    vector<pair<string, string>> result;

    for (int i = 0; i < oldNames.size(); i++) {
        result.push_back({oldNames[i], newNames[i]});
    }

    sort(result.begin(), result.end());

    cout << result.size() << '\n';

    for (int i = 0; i < result.size(); i++) {
        cout << result[i].first << " "
             << result[i].second << '\n';
    }

    return 0;
}