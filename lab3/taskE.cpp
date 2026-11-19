#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int count(vector<int>& a,int L,int R){
    auto left=lower_bound(a.begin(),a.end(),L);
    auto right=upper_bound(a.begin(),a.end(),R);
    return right-left;
}

int main(){
    int n,q;
    cin>>n>>q;

    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());

    while(q--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;

        int answer;
        if(r1<l2 || r2<l1){
            answer=count(a,l1,r1)+count(a,l2,r2);
        }
        else{
            int L=min(l1,l2);
            int R=max(r1,r2);
            answer=count(a,L,R);
        }
        cout<<answer<<'\n';
    }
    return 0;
}