#include <iostream>;
using namespace std;

struct Node{
    int value;
    Node* next;
};
int main(){
    int n;
    cin>>n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i=0;i<n;i++){
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
    if(n == 1){
        head = nullptr;
    }else{
        int middle = n/2+1;
        Node* cur = head;

        for (int i=1;i<middle-1;i++){
            cur=cur->next;
        }
        cur->next=cur->next->next;
    }
    Node* cur = head;

    while(cur!=nullptr){
        cout<<cur->value<<" ";
        cur=cur->next;
    }
    cout<<'\n';
    return 0;
}