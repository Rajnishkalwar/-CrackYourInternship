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
    TreeNode* helper(TreeNode* root){
          if(root->left==nullptr){
            return root->right;
          }
          if(root->right==nullptr){
            return root->left;
          }
          TreeNode* leftpart=root->left;
          TreeNode* rightleftmost=findlast(root->right);
          rightleftmost->left=leftpart;
          return root->right;
    }
    TreeNode* findlast(TreeNode* root){
        if(root->left==nullptr){
            return root;
        }
        return findlast(root->left);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return nullptr;
        }
        if(root->val==key){
            return helper(root);
        }
        TreeNode* temp=root;
        while(temp!=nullptr){
            if(temp->val>key){
                if(temp->left!=nullptr && temp->left->val==key){
                    temp->left=helper(temp->left);
                }
                else{
                    temp=temp->left;
                }

            }
            else{
                if(temp->right!=nullptr && temp->right->val==key){
                    temp->right=helper(temp->right);
                }
                else{
                    temp=temp->right;
                }

            }
        }
        return root;
        
    }
};