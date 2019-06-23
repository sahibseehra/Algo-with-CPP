pair<int,int> fuc(Node *root)
{
    if(root)
    {
        pair<int,int> p1=fuc(root->left);
        pair<int,int> p2=fuc(root->right);
        return make_pair(max(p1.first,max(p2.first,p1.second+p2.second+1)),max(p1.second,p2.second)+1);
    }
    return make_pair(0,0);
}
int diameter(Node* root)
{
    pair<int,int> p=fuc(root);
    return p.first;
   // Your code here
}
