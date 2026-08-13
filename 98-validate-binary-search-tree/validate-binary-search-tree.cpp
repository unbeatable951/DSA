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
    long long prev = LLONG_MIN;

    bool isValidBST(TreeNode* root) {

        if (root == nullptr) {
            return true;
        }

        // Go to left subtree
        if (!isValidBST(root->left)) {
            return false;
        }

        // Check current node
        if (root->val <= prev) {
            return false;
        }

        // Update previous value
        prev = root->val;

        // Go to right subtree
        return isValidBST(root->right);
    }
};