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
    vector<vector<int>> getOrder(TreeNode* node, vector<vector<int>> &result) {
        if (node == nullptr) {
            return result;
        }
        
        queue<TreeNode*> queuenode;
        queuenode.push(node);
        bool flag = true; // true for left-to-right, false for right-to-left
        
        while (!queuenode.empty()) {
            int size = queuenode.size();
            vector<int> arr(size); // Prepare to store current level values
            
            for (int i = 0; i < size; i++) {
                TreeNode* current = queuenode.front();
                queuenode.pop();
                
                // Calculate the index based on traversal direction
                int index = flag ? i : (size - 1 - i);
                arr[index] = current->val;
                
                // Add children to the queue
                if (current->left) {
                    queuenode.push(current->left);
                }
                if (current->right) {
                    queuenode.push(current->right);
                }
            }
            
            flag = !flag; // Toggle direction for the next level
            result.push_back(arr); // Add current level to the result
        }
        
        return result;
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        getOrder(root, result);
        return result;
    }
};
