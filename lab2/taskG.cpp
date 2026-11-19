#include <iostream>
#include <string>
using namespace std;
struct Node{
    string value;
    Node* next;   
};
int main(){
    int k,n;
    cin>>n>>k;
    Node* head=nullptr;
    Node* tail=nullptr;

    for(int i=0;i<n;i++){
        string word;
        cin>>word;

        Node* newNode = new Node{word,nullptr};
        if(head == nullptr){
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    if(n==0){
        cout<<'\n';
        return 0;
    }
    k=k%n;

    if(k==0){
        Node* cur=head;

        while(cur!=nullptr){
            cout<<cur->value<<" ";
            cur=cur->next;
        }
        cout<<'\n';
        return 0;
    }
    Node* newTail=head;
    for(int i=1;i<k;i++){
        newTail=newTail->next;
    }
    Node* newHead=newTail->next;
    tail->next=head;
    newTail->next=nullptr;
    head=newHead;
    Node* cur=head;

    while(cur!=nullptr){
        cout<<cur->value<<" ";
        cur=cur->next;
    }
    cout<<'\n';
    return 0;
}