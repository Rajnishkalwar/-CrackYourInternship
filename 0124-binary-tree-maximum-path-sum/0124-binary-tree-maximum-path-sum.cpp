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
class Solution {
public:
    int maxipath(TreeNode* node, int &maxi){
        if(node==nullptr) return 0;
        int lftree=max(0, maxipath(node->left,maxi));
        int rgtree=max(0,maxipath(node->right,maxi));
        maxi=max(lftree+rgtree+node->val,maxi);
        return node->val+max(lftree,rgtree);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxipath(root,maxi);
        return maxi;   
    }
};