#include <iostream>
#include <deque>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        deque<int> q;

        for(int i=n;i>=1;i--){
            q.push_front(i);

            int k=i%q.size();
            for(int j=0;j<k;j++){
                q.push_front(q.back());
                q.pop_back();
            }
        }
        for(int x : q){
            cout<< x << " ";
        }
        cout<<'\n';
    }
    return 0;
}