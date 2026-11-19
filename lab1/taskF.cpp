#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    string result1 = "";
    string result2 = "";
    string result = "";
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i]=="#") {
            result.pop_back();
        } else {
            result.push_back(s1[i]);
        }
    }
    for (int j = 0; j < s2.length(); i++) {
        if (s2[j]=="#") {
            result.pop_back();
        } else {
            result.push_back(s2[j]);
        }
    }
    if (result.empty() == false) {
        result.pop_back();
    }
    if(s1==s2){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}