#include <iostream>
using namespace std;
struct Node{
    long long value;
    Node* next;
};
int main(){
    int n;
    cin>>n;
    Node* head=nullptr;
    Node* tail= nullptr;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        Node* newNode=new Node{x,nullptr};
        if(head==nullptr){
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    long long current=head->value;
    long long best=head->value;
    Node* cur=head->next;

    while(cur!=nullptr){
        current=max(cur->value,current+cur->value);
        best=max(best,current);
        cur=cur->next;
    }
    cout<<best<<'\n';
    return 0;
}