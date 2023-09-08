class Solution {
public:
    TreeNode *create(vector<int> &preorder,int &i,int high)
    {
        if(i==preorder.size() || preorder[i]>high)
        return NULL;
        TreeNode *temp=new TreeNode(preorder[i]);
        i++;
        temp->left=create(preorder,i,temp->val);
        temp->right=create(preorder,i,high);
        return temp;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return create(preorder,i,INT_MAX);

    }
};