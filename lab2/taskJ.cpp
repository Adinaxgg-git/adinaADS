#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};
Node* inserts(Node* head,int x,int p){
    Node*newNode=new Node{x,nullptr};
    if(p==0){
        newNode->next=head;
        return newNode;
    }
    Node* cur=head;
    for(int i=0;i<p-1;i++){
        cur=cur->next;

    }
    newNode->next=cur->next;
    cur->next=newNode;
    return head;
}
Node* remove(Node* head,int p){
    if(p==0){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;

    }
    Node*cur=head;
    for(int i=0;i<p-1;i++){
        cur=cur->next;
    }
    Node* temp=cur->next;
    cur->next=cur->next->next;
    delete temp;
    return head;
}
void print(Node* head){
    if(head==nullptr){
        cout<<-1<<'\n';
        return;
    }
    Node* cur=head;
    while(cur!= nullptr){
        cout<<cur->value<<" ";
        cur=cur->next;

    }
    cout<<'\n';
}
Node* replace(Node* head,int p1,int p2){
    if(p1==p2){
        return head;
    }
    Node* moving;
    if(p1==0){
        moving=head;
        head=head->next;
    }else{
        Node* cur=head;

        for(int i=0;i<p1-1;i++){
            cur=cur->next;
        }
        moving =cur->next;
        cur->next=moving->next;
    }
    if(p2==0){
        moving->next=head;
        head=moving;
        return head;
    }
    Node* cur=head;
    for(int i=0;i<p2-1;i++){
        cur=cur->next;
    }
    moving->next=cur->next;
    cur->next=moving;
    return head;
}
Node* reverse(Node* head){
    Node* prev=nullptr;
    Node* cur=head;

    while(cur!=nullptr){
        Node* next =cur->next;
        cur->next=prev;

        prev=cur;
        cur= next;
    }
    return prev;
}
Node* cyclic_left(Node* head,int x){
    if(head==nullptr||x==0){
        return head;
    }Node* newTail=head;
    for(int i=1;i<x;i++){
        newTail=newTail->next;
    }
    Node* newHead =newTail->next;
    Node*tail=newHead;

    while(tail->next!=nullptr){
        tail=tail->next;
    }
    tail->next=head;
    newTail->next=nullptr;
    return newHead;
}
Node* cyclic_right(Node* head,int x){
    if(head==nullptr||x==0){
        return head;
    }
    int n=0;
    Node* cur=head;

    while(cur!=nullptr){
        n++;
        cur=cur->next;
    }
    x=x%n;

    if(x==0){
        return head;
    }
    int leftShift=n-x;
    return cyclic_left(head,leftShift);
}
int main(){
    Node* head=nullptr;

    int command;
    while(cin>> command){
        if(command==0){
            break;
        }
        if(command==1){
            int x,p;
            cin>>x>>p;
            head=inserts(head,x,p);
        }
        else if(command==2){
            int p;
            cin>>p;
            head=remove(head,p);
        }
        else if(command==3){
            print(head);
        }
        else if(command==4){
            int p1,p2;
            cin>>p1>>p2;
            head=replace(head,p1,p2);
        }
        else if(command==5){
            head=reverse(head);
        }
        else if(command==6){
            int x;
            cin>>x;
            head=cyclic_left(head,x);
        }
        else if(command==7){
            int x;
            cin>>x;
            head=cyclic_right(head,x);
        }
    }
    return 0;
}