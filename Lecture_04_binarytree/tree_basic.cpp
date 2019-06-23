#include<iostream>
#include<queue>
using namespace std;


class node{
public:
    int data;
    node*left;
    node*right;
    node(int d):data(d),left(NULL),right(NULL){}
};

void printTree(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" = ";
    if(root->left){
        cout<<root->left->data<<",";
    }
    if(root->right){
        cout<<root->right->data;
    }
    cout<<endl;

    printTree(root->left);
    printTree(root->right);

}

node* takeInput(){
    int data;

    cin>>data;
    node*n = NULL;

    if(data!=-1){
        n = new node(data);
        n->left = takeInput();
        n->right = takeInput();
    }
    return n;
}
node* takeInputLevel(){
    int d;
    node*root = NULL;
    cout<<"Enter root data ";
    cin>>d;
    root = new node(d);

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* f = q.front();
        q.pop();

        int d1,d2;
        cout<<"Enter children of "<<f->data<<"  - ";
        cin>>d1>>d2;
        if(d1!=-1){
            f->left = new node(d1);
            q.push(f->left);
        }
        if(d2!=-1){
            f->right = new node(d2);
            q.push(f->right);
        }
    }
    return root;



}
istream& operator>>(istream& is,node*&root){
    root = takeInputLevel();
    return is;
}
ostream& operator<<(ostream& os,node* root){
    printTree(root);
    return os;
}
void preOrder(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(node*root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(node*root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){

    node*root = NULL;
    cin>>root;
    cout<<root;

    cout<<endl;
    preOrder(root);

    cout<<endl;
    inOrder(root);

    cout<<endl;
    postOrder(root);
    cout<<endl;





return 0;
}
