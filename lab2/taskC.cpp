#include <iostream>
#include <string>
using namespace std;

struct Node{
    string value;
    Node* next;
};
int main(){
    int n;
    cin>>n;
    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        Node* newNode = new Node{name, nullptr};

        if(head==nullptr){
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    Node* cur=head;

    while(cur!=nullptr && cur->next != nullptr){
        if(cur->value==cur->next->value){
            cur->next=cur->next->next;
        }else{
            cur=cur->next;
        }
    }
    int count=0;
    cur=head;
    while(cur!=nullptr){
        count++;
        cur=cur->next;
    }

    cout<<count<<'\n';
    cur=head;

    while(cur!= nullptr){
        cout<<cur->value<<'\n';
        cur=cur->next;
    }
    return 0 ;
}