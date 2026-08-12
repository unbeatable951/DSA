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

    int height(TreeNode* root, int& diameter) {

        if (root == nullptr) {
            return 0;
        }

        int leftHeight = height(root->left, diameter);
        int rightHeight = height(root->right, diameter);

        // Diameter passing through current node
        diameter = max(diameter, leftHeight + rightHeight);

        // Return height to parent
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        int diameter = 0;

        height(root, diameter);

        return diameter;
    }
};