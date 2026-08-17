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
    int getSize(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return getSize(root->left) + getSize(root->right) + 1;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) {
            return 0;
        }

        int sizeOfLeftSubtree = getSize(root->left);
        if (sizeOfLeftSubtree >= k) {
            return kthSmallest(root->left, k);
        } else if (sizeOfLeftSubtree + 1 == k) {
            return root->val;
        } else {
            return kthSmallest(root->right, k - sizeOfLeftSubtree - 1);
        }

        // return 0;
    }
};
