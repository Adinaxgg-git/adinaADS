#include <iostream>
#include <vector>
#include <string>
using namespace std;
void mergeSort(vector<string>& a,int l,int r){
    if (l>=r) return;
    int m=l+(r-l)/2;
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);

    vector<string> temp;
    int i=l,j=m+1;
    while(i<=m && j<=r){
        if(a[i].size()<=a[j].size()){
            temp.push_back(a[i++]);
        }else{
            temp.push_back(a[j++]);
        }
    }
    while(i<=m) temp.push_back(a[i++]);
    while(j<=r) temp.push_back(a[j++]);

    for(int k=0;k<(int)temp.size();k++){
        a[l+k]=temp[k];
    }
}
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        vector<string> a;
        string word="";
        for(char c : s){
            if(c==' '){
                if(!word.empty()){
                    a.push_back(word);
                    word="";
                }
            }else{
                word=word+c;
            }
        }
        if(!word.empty()) a.push_back(word);
        if(!a.empty()){
            mergeSort(a,0,(int)a.size()-1);
        }
        for(int i=0;i<(int)a.size();i++){
            if(i>0) cout<<' ';
            cout<<a[i];
        }
        cout<<'\n';
    }
    return 0;
}s