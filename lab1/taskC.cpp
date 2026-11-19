#include <iostream>
using namespace std;

int main(){
    int a;
    int sum=1;
    cin>>a;
    if(a<=1){
        cout << "NO";
        return 0;
    }
    for (int i=2; i<a+1;i++){
        if(a%i==0){
            sum=sum+1;
        }
    }
    if(sum>2){
        cout << "NO";
    }else{
        cout << "YES";
    }
}
