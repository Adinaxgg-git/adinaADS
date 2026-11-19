#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};

Node* builderlist(int n){
    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        Node* newNode = new Node{x,nullptr};

        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}
int main(){
    int n1;
    cin>>n1;

    Node* head1 = builderlist(n1);
    int n2;
    cin>>n2;

    Node* head2 = builderlist(n2);

    Node* cur1 = head1;
    Node* cur2 = head2;
    if(cur1 == nullptr){
        Node* cur=cur2;

        while(cur!= nullptr){
            cout<<cur->value<<" ";
            cur=cur->next;
        }
        cout<<'\n';
        return 0;
    }
    if(cur2 == nullptr){
        Node* cur = cur1;

        while(cur!=nullptr){
            cout<<cur->value<<" ";
            cur = cur->next;
        }
        cout<<'\n';
        return 0;
    }
    Node* head;
    Node* tail;

    if(cur1->value<= cur2->value){
        head=cur1;
        cur1=cur1->next;
    }else{
        head=cur2;
        cur2=cur2->next;
    }
    tail=head;

    while(cur1!=nullptr && cur2!= nullptr){
        if(cur1->value<=cur2->value){
            Node* chosen=cur1;
            cur1=cur1->next;

            tail->next = chosen;
            tail=chosen;
        }else{
            Node* chosen= cur2;
            cur2=cur2->next;

            tail->next=chosen;
            tail=chosen;
        }
    }
    if(cur1!=nullptr){
        tail->next=cur1;
    }else{
        tail->next=cur2;
    }
    Node* cur=head;
    while(cur!=nullptr){
        cout<<cur->value<<" ";
        cur=cur->next;
    }
    cout<<'\n';
    return 0;
}