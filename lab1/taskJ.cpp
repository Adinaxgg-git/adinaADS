#include <iostream>
#include <queue>

using namespace std;
bool wins(int c1, int c2){
    if(c1==0 && c2 ==9) return true;
    if(c1==9 && c2==0) return false;
    return c1>c2;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    queue<int> boris,nursik;

    for(int i=0;i<5;i++){
        int card;
        cin>>card;
        boris.push(card);

    }
    for(int i=0;i<5;i++){
        int card;
        cin>>card;
        nursik.push(card);
    }
    int moves=0;

    while(!boris.empty()&&!nursik.empty()){
        int c1=boris.front();boris.pop();
        int c2=nursik.front();nursik.pop();
        moves++;
        if(wins(c1,c2)){
            boris.push(c1);
            boris.push(c2);
        }else{
            nursik.push(c1);
            nursik.push(c2);
        }
    }
    if(!boris.empty()){
        cout<< "Boris " << moves << "\n";
    }else{
        cout<< "Nursik " << moves << "\n";
    }
    return 0;
}