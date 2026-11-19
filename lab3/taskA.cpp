#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int a[1000];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int x;
    cin>>x;


    int left=0;
    int right=n-1;
    while(left<=right){
        int mid=(right+left)/2;

        if(a[mid]==x){
            cout<<"Yes";
            return 0;
        }
        else if(a[mid]<x){
            left=mid+1;

        }
        else{
            right=mid-1;
        }
    }
    cout<<"No";
    return 0;
}