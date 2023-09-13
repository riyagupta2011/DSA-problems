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
class NodeValue{
    public:
       int sum,maxNode,minNode,maxSize;
    NodeValue(int sum,int minNode,int maxNode,int maxSize)
    {
        this->sum=sum;
        this->maxNode=maxNode;
        this->minNode=minNode;
        this->maxSize=maxSize;
    }
};
class Solution {
public:
int maxSum=INT_MIN;
    NodeValue helper(TreeNode *root)
    {
        if(root==NULL)
        return NodeValue(0,INT_MAX,INT_MIN,0);

        auto left=helper(root->left);
        auto right=helper(root->right);

        if(left.maxNode < root->val && right.minNode >root->val)
        {
            maxSum=max(maxSum,left.sum+right.sum +root->val);
            return NodeValue(left.sum+right.sum +root->val,min(root->val,left.minNode),max(root->val,right.maxNode),left.maxSize+right.maxSize+1);
        }
        return NodeValue(0,INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
    }
    int maxSumBST(TreeNode* root) {
        NodeValue ans= helper(root);
        if(maxSum<0)
        return 0;
        return maxSum;
    }
};