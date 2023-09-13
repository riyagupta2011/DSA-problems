int floorInBST(TreeNode<int> * root, int x)
{
    // Write your code here.
    if(root==NULL)
    return -1;
    int ans=0;
    while(root)
    {
        if(root->val > x)
        {
            root=root->left;
        }
        else if(root->val <x)
        {
            ans=root->val;
            root=root->right;
        }
        else
        return x;
    }
    return ans;
}