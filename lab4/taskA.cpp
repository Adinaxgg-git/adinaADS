#include <iostream>
#include <string>
using namespace std;
struct Node{
    int value;
    Node* left;
    Node* right;

    Node(int v){
        value=v;
        left=nullptr;
        right=nullptr;
    }
};

void insertNode(Node*& root,int value){
    if(root==nullptr){
        root=new Node(value);
        return;
    }
    Node* current=root;

    while(true){
        if(value<=current->value){
            if(current->left==nullptr){
                current->left =new Node(value);
                return;
            }
            current=current->left;
            
        }
        else{
            if(current->right==nullptr){
                current->right=new Node(value);
                return;
            }
            current=current->right;
        }
    }
}
bool checkPath(Node* root,const string&path){
    Node* current=root;

    for(char direction : path){
        if(current==nullptr){
            return false;
        }
        if(direction=='L'){
            current=current->left;
        }
        else{
            current=current->right;
        }
    }
    return current!=nullptr;
}
int main() {
    int n,m;
    cin>>n>>m;
    Node* root=nullptr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insertNode(root,x);
    }
    for(int i=0;i<m;i++){
        string path;
        cin>>path;
        if(checkPath(root,path)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}