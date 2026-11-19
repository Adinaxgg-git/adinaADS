#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<long long> prefix(n);
    prefix[0]=a[0];

    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+a[i];
    }
    int q;
    cin>>q;

    while(q--){


        int power;
        cin>>power;

        auto pos=upper_bound(a.begin(),a.end(),power);

        int count=pos-a.begin();

        long long sum;
        if(count==0){
            sum=0;
        }else{
            sum=prefix[count-1];
        }
        cout<<count<<" "<<sum<<'\n';
    
    }
    return 0;
}