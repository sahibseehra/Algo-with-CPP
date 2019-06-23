
bool mirr(TreeNode *root1,TreeNode *root2)
{
    if(root1==NULL&&root2==NULL)
    return true;
    if(root1==NULL||root2==NULL)
    return false;
    
    if(root1->val==root2->val&&mirr(root1->left,root2->right)&&mirr(root1->right,root2->left))
    return true;
    
    return false;
}
int Solution::isSymmetric(TreeNode* root) {
    if(root==NULL)
    return 1;
    if(mirr(root->left,root->right))
    return 1;
    return 0;
}
