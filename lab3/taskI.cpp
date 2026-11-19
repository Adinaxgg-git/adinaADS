#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool canSplit(const vector<long long>&a,int k,long long maxSum){
int blocks=1;
long long currentSum=0;
for(int i=0;i<a.size();i++){
    if(currentSum+a[i]<=maxSum){
    currentSum+=a[i];
    }else{
    blocks++;
    currentSum=a[i];
    }
}
return blocks<=k;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<long long>a(n);
    long long left=0;
    long long right=0;
    for(int i=0;i<n;i++){
       cin>>a[i];
       left=max(left,a[i]);
       right+=a[i];
    }
    while(left<right){
        long long mid=left+(right-left)/2;
        if(canSplit(a,k,mid)){
           right=mid;
        }else{
           left=mid+1;
        }
    }
    cout<<left<<endl;
    return 0;
}