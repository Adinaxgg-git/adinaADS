#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    sort(s.begin(),s.end());
    string vowels="";
    string cons="";
    for(char c : s){
        if(c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u'){
            vowels+=c;
        }else{
            cons+=c;
        }
    }
    cout<<vowels<<cons<<'\n';
    return 0;
}