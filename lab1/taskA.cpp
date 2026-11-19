#include <iostream>
using namespace std;

int main(){
    long long a,b;
    cin>>a>>b;
    
    if (a<b){
        swap(a,b);
    }
    while (a%b!=0){
        long long x=a%b;

        a=b;
        b=x;

    }
    cout<<b;
}