class Solution {
public:
     bool valid(TreeNode *root,long  mini,long maxi)
   {
      if(root==NULL)
      return true;
      if(root->val>=maxi || root->val<=mini)
      return false;
      return valid(root->left,mini,root->val) && valid(root->right,root->val,maxi);
   }
    bool isValidBST(TreeNode* root) {
        bool ans=valid(root,LONG_MIN,LONG_MAX);
        return ans;
    }
};