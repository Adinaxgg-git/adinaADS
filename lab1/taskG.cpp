#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin>>s;
    string st="";
    for(int i=0;i<s.length();i++){
        if(!st.empty()&& st.back()==s[i]){
            st.pop_back();
        }else{
            st.push_back(s[i]);
        }
    }
    if(st.empty()){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}