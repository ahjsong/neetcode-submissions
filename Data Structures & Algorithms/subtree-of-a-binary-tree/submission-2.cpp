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
private:
    bool helperFunction(TreeNode* root, TreeNode* subRoot) {
        queue<pair<TreeNode*, TreeNode*>> queue;
        queue.push({root, subRoot});
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
        // if (!left.empty() || !right.empty()) {
        //     return false;
        // }
        return true;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            if (current->val == subRoot->val) {
                if (helperFunction(current, subRoot)) {
                    return true;
                }
            }
            if (current->left) {
                queue.push(current->left);
            }
            if (current->right) {
                queue.push(current->right);
            }
            queue.pop();
        }
        return false;
    }
};
