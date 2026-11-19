#include <iostream>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long i=2;

    while(i<=n/i){
        while(n%i==0){
            cout<<i<<" ";
            n=n/i;
        }
        i++;

    }
    if(n>1){
        cout<<n;
    }
    return n;
}