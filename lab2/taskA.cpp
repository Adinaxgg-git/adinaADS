#include <iostream>
#include <queue>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int count[26]={};
        queue<char> q;

        for(int i=0;i<n;i++){
            char c;
            cin>>c;

            count[c-'a']++;
            q.push(c);

            while(!q.empty() && count[q.front()-'a']!=1){
                q.pop();
            }
            if(q.empty()){
                cout<<-1<<" ";
            }else{
                cout<<q.front()<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}