#include <iostream>
#include <string>
using namespace std;

struct Node{
    string value;
    Node* prev;
    Node* next;
};

int main(){
    Node* head=nullptr;
    Node* tail=nullptr;

    string command;

    while(cin>>command){
        if(command=="add_front"){
            string title;
            cin>>title;
            Node* newNode=new Node{title,nullptr,nullptr};
            if(head==nullptr){
                head=newNode;
                tail=newNode;
            }else{
                newNode->next=head;
                head->prev=newNode;
                head=newNode;
            }
            cout<<"ok"<<'\n';
        }
        else if(command=="add_back"){
            string title;
            cin>>title;
            Node* newNode=new Node{title,nullptr,nullptr};
            if(tail==nullptr){
                head=newNode;
                tail=newNode;
            }else{
                newNode->prev=tail;
                tail->next=newNode;
                tail=newNode;
            }
            cout<<"ok"<<'\n';
        }
        else if (command =="erase_front"){
            if(head==nullptr){
                cout<<"error"<<'\n';
            }else{
                cout<<head->value<<'\n';

                Node* oldHead=head;
                if(head== tail){
                    head=nullptr;
                    tail=nullptr;
                }else{
                    head=head->next;
                    head->prev=nullptr;
                }
                delete oldHead;
            }
        }
        else if(command=="erase_back"){
            if(tail==nullptr){
                cout<<"error"<<'\n';
            }else{
                cout<<tail->value<<'\n';

                Node* oldTail=tail;
                if(head==tail){
                    head=nullptr;
                    tail=nullptr;
                }else{
                    tail=tail->prev;
                    tail->next=nullptr;
                }
                delete oldTail;
            }
        }
        else if(command=="front"){
            if(head==nullptr){
                cout<<"error"<<'\n';
            }else{
                cout<<head->value<<'\n';
            }
        }
        else if(command=="back"){
            if(tail==nullptr){
                cout<<"error"<<'\n';
            }else{
                cout<<tail->value<<'\n';
            }
        }
        else if(command =="clear"){
            while(head!=nullptr){
                Node* temp=head;
                head=head->next;
                delete temp;
            }
            tail=nullptr;
            cout<<"ok"<<'\n';
        }
        else if(command=="exit"){
            cout<<"goodbye"<<'\n';
            break;
        }
    }
    return 0;
}