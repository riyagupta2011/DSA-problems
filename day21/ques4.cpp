class Solution
{
    public:
    void findInorder(vector<int> &inorder,Node *root)
    {
        if(root==NULL)
        return;
        findInorder(inorder,root->left);
        inorder.push_back(root->data);
        findInorder(inorder,root->right);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        vector<int> inorder;
        findInorder(inorder,root);
        int n=inorder.size();
        int x=n-K;
        return inorder[x];
    }
};