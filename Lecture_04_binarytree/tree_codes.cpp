#include<iostream>
#include<queue>
#include<cmath>
using namespace std;


class node{
public:
    int data;
    node*left;
    node*right;

    node(int d):data(d),left(NULL),right(NULL){}
};

node* build(){
    node* root = NULL;
    int d;
    cin>>d;
    if(d!=-1){
        root = new node(d);
        root->left = build();
        root->right = build();
    }
    return root;
}
void print(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" => ";
    if(root->left!=NULL){
        cout<< root->left->data<<",";
    }
    if(root->right!=NULL){
        cout<<root->right->data<<",";
    }
    cout<<endl;

    print(root->left);
    print(root->right);

}
void levelOrderInput(node*&root){

    cout<<"Enter root data ";
    int d;
    cin>>d;

    root = new node(d);
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* f = q.front();
        q.pop();
        cout<<"Enter the children of "<<f->data<<" ";
        int d1,d2;
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
}
void levelOrderPrint(node*root){
   queue<node*> q;
   q.push(root);
   q.push(NULL);

   while(!q.empty()){
        node*f = q.front();
        q.pop();
        if(f==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<< f->data<<" ";
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
   }
}

void preOrderPrint(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}
void inOrderPrint(node*root){
    if(root==NULL){
        return;
    }
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);
}

void postOrderPrint(node*root){
    if(root==NULL){
        return;
    }
    postOrderPrint(root->left);
    postOrderPrint(root->right);
    cout<<root->data<<" ";

}

istream& operator>>(istream&is,node*&root){
    levelOrderInput(root);
    return is;
}
ostream& operator<<(ostream&os, node*root){
    levelOrderPrint(root);
    return os;
}

int height(node*root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}

int sum(node*root){
    if(root==NULL){
        return 0;
    }
    return sum(root->left)+sum(root->right)+root->data;
}
int updateTreeWithSum(node*root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    int temp = root->data;

    int leftSum = updateTreeWithSum(root->left);
    int rightSum = updateTreeWithSum(root->right);

    root->data = leftSum + rightSum;

    return temp + root->data;
}



int diameter(node*root){
    if(root==NULL){
        return 0;
    }
    int op1 = height(root->left) + height(root->right);
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1,max(op2,op3));
}

class Pair{
public:
    int height;
    int diameter;
};

Pair fastDiameter(node*root){
    Pair p;
    if(root==NULL){
        p.height = 0;
        p.diameter = 0;
        return p;
    }

    ///Rec Case

    Pair leftPair = fastDiameter(root->left);
    Pair rightPair = fastDiameter(root->right);

    int op1 = leftPair.height + rightPair.height;
    int op2 = leftPair.diameter;
    int op3 = rightPair.diameter;

    p.diameter = max(op1,max(op2,op3));
    p.height = max(leftPair.height,rightPair.height)+1;
    return p;
}

/// Pair - First(int) Height, Second(Bool) - Balanced

pair<int,bool> isBalanced(node*root){
    pair<int,bool> p;
    if(root==NULL){
            p.first = 0;
            p.second = true;
            return p;
    }

    pair<int,bool> left = isBalanced(root->left);
    pair<int,bool> right = isBalanced(root->right);

    p.first = max(left.first,right.first)+1;
    if(left.second && right.second && abs(left.first-right.first)<=1){
        p.second = true;
    }
    else{
        p.second = false;
    }
    return p;
}

class myPair{
public:
    int inc;
    int exc;
};

myPair maxSumParentOrChild(node*root){
    myPair p;
    if(root==NULL){
        p.inc = 0;
        p.exc = 0;
        return p;
    }
    myPair left = maxSumParentOrChild(root->left);
    myPair right = maxSumParentOrChild(root->right);

    p.inc = root->data + left.exc + right.exc;
    p.exc = max(left.inc,left.exc) + max(right.inc,right.exc);


    return p;


}


int main(){
    node*root = NULL;
    cin>>root;
    cout<<root;

    if(isBalanced(root).second){
        cout<<"Tree is balanced! "<<endl;
    }
    else{
        cout<<"Not balanced "<<endl;
    }

    cout<<maxSumParentOrChild(root).exc<<endl;
    cout<<maxSumParentOrChild(root).inc<<endl;


}

