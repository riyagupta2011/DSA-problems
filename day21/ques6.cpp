class BSTIterator {
public:
stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode *t=st.top();
        st.pop();
        pushAll(t->right);
        return t->val;
    }
    
    bool hasNext() {
        if(!st.empty())
        return true;
        return false;
    }
    void pushAll(TreeNode *root)
    {
        while(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }
    }
};