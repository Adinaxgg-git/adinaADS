#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;

};
int main(){
    int n;
    cin>>n;
    Node* head=nullptr;
    Node* tail=nullptr;

    for(int i=0;i<n;i++){
        int x;
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
    Node* cur=head;

    while(cur!=nullptr && cur->next!=nullptr){
        cur->next=cur->next->next;
        cur=cur->next;

    }
    cur=head;
    while(cur!=nullptr){
        cout<<cur->value<<" ";
        cur=cur->next;
    }
    return 0;
}