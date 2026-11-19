#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> ends(n);

    int sum=0;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        sum=sum+x;
        ends[i]=sum;
    }
    for(int i=0;i<m;i++){
        int mistake;
        cin>>mistake;

        auto pos=lower_bound(ends.begin(),ends.end(),mistake);

        cout<<pos-ends.begin()+1<<'\n';
    }
    return 0;
}