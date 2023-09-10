class Solution
{
    public:
    void inorder(Node *root,Node *&pre,Node *&suc,int key)
    {
        if(root==NULL)
        return;
        if(root->left)
        inorder(root->left,pre,suc,key);
        if(root->key>key && suc==NULL)
        {
            suc=root;
            return;
        }
        if(root->key<key)
        pre=root;
        
        if(root->right)
        inorder(root->right,pre,suc,key);
        
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        pre=NULL;
        suc=NULL;
        inorder(root,pre,suc,key);
    }
};

