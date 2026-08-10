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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> queue;
        // if (!p && !q) {
        //     return true;
        // }
        // if (!p || !q) {
        //     return false;
        // }

        queue.push({p, q});
        while (!queue.empty()) {
            TreeNode* left = queue.front().first;
            TreeNode* right = queue.front().second;
            queue.pop();
            if (!left && !right) {
                continue;
            }
            if (!left || !right) {
                return false;
            }
            if (left->val != right->val) {
                return false;
            }
            queue.push({left->left, right->left});
            queue.push({left->right, right->right});
        }
        return true;
    }
};
