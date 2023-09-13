class Solution {
public:
 void find(TreeNode* root, int& cnt, int k, TreeNode*& ans) {
        if (root == NULL || cnt >= k) {
            return;
        }

        find(root->left, cnt, k, ans);
        cnt++;

        if (cnt == k) {
            ans = root;
            return;
        }

        find(root->right, cnt, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
         TreeNode* ans = NULL;
        int cnt = 0;
        find(root, cnt, k, ans);
        return ans->val;
    }
};