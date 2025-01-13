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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root=helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
        
    }
    TreeNode* helper(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder, int     inStart,int inEnd,map<int,int> &mpp ){
        if(preStart>preEnd || inStart>inEnd){
            return nullptr;
        }
        TreeNode* root=new TreeNode (preorder[preStart]);
        int inRoot=mpp[root->val];
        int Leftval=inRoot-inStart;
        root->left=helper(preorder,preStart+1,preStart+Leftval,inorder,inStart,inRoot-1,mpp);
        root->right=helper(preorder,preStart+Leftval+1,preEnd,inorder,inRoot+1,inEnd,mpp);
        return root;

    }
};