vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* root) {
    map<int,vector<int> > m;
    
    vector<vector<int> >cou;
    queue<pair<TreeNode*,int> > q;
    if(root)
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<TreeNode*,int>  np=q.front();
        q.pop();
       // cout<<np.second<<" "<<np.first->val<<"\n";
        m[np.second].push_back(np.first->val);
        
        if(np.first->left!=NULL)
           q.push(make_pair(np.first->left,np.second-1));
        if(np.first->right!=NULL)
           q.push(make_pair(np.first->right,np.second+1));
        
        
    }
    for(map<int,vector<int> >::iterator it=m.begin();it!=m.end();it++)
    cou.push_back(it->second);
    return cou;
}

