/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator{
    public:
    stack<TreeNode *> st;
    bool reverse=true;

    BSTIterator(TreeNode *root,bool isreverse)
      {
          reverse=isreverse;
          pushAll(root);
      }

    void pushAll(TreeNode* root)
    {
        while(root!=NULL)
        {
            st.push(root);
            if(reverse==true)
            root=root->right;
            else
            root=root->left;
        }
    }

    int next()
    {
        TreeNode *temp=st.top();
        st.pop();
        if(reverse)
        {
            pushAll(temp->left);
        }
        else
        pushAll(temp->right);
        return temp->val;
    }
 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
        return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            if(i+j==k)
            return true;
            if(i+j >k)
            j=r.next();
            else
            i=l.next();
        }
        return false;
    }
};