#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class node
{
    public: 
    int data;
    node *next;

    int operator[](int p){
        if(p==0){
            return data;
        }
        else{
            ///Take P-1 Jumps
            node*temp = next;
            int jump=1;
            while(jump<=p-1){
                jump++;
                temp = temp->next;
            }
            return temp->data;
        }

    }
    
    
};

node *create_node(int d)
{
    node *n=new node;
    n->data=d;
    n->next=NULL;

    return n;
}

node* insert_node_head(node *np,node* head)
{
    np->next=head;
    head=np;

    return head;
}


void print(node *head )
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
}

node *insertatTail(node*np, node* head)
{
    
    node *temp=head;
    if(head==NULL)
    {
        head=np;
        return head;
    }

    while(temp->next!=NULL)
    temp=temp->next;

    temp->next=np;
    return head;


}
node *mid_point(node *head)
{
    node *slow=head;
    node *fast=head->next;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int main()
{
    node *head=NULL;
    while(1)
    {
        cout<<"Enter the value of node\n";
        int d;
        cin>>d;
        if(d==-1)
        break;


        node* np=create_node(d);

       // head=insert_node_head(np,head);
       head=insertatTail(np,head);
    }

    print(head);

    //cout<<(*head)[3]<<"\n";

    node * np = mid_point(head);
    cout<<np->data<<" --\n";
    
}

