#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool can(vector<int>& a,long long k,long long h){
    long long hours=0;

    for(int x:a){
        hours+=(x+k-1)/k;
        if(hours>h){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    long long h;
    cin>>n>>h;
    vector <int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long left=1;
    long long right=*max_element(a.begin(),a.end());

    while(left<right){
        long long mid=(left+right)/2;

        if(can(a,mid,h)){
            right=mid;
        }else{
            left=mid+1;
        }
    }
    cout<<left<<'\n';
    return 0;
}