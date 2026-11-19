#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int minDiff=INT_MAX;
    for(int i=1;i<n;i++){
        int diff=a[i]-a[i-1];
        if(diff<minDiff){
            minDiff=diff;
        }
    }
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]==minDiff){
            cout<<a[i-1]<<" "<<a[i]<<" ";
        }
    }
    cout<<'\n';
    return 0;
}