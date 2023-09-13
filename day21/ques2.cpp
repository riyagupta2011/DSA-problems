int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    if(node==NULL)
    return -1;
    int ans=-1;
    while(node)
    {
        if(node->data >x)
        {
            ans=node->data;
            node=node->left;
        }
        else if(node->data <x)
        {
            
            node=node->right;
        }
        else
        return x;
    }
    return ans;
}