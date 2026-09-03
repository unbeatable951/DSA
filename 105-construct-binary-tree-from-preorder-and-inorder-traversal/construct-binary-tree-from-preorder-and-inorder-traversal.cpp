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

    int preIndex = 0;

    TreeNode* buildTreeHelper(vector<int>& preorder,
                              vector<int>& inorder,
                              int inStart,
                              int inEnd) {

        // No elements
        if (inStart > inEnd)
            return nullptr;

        // First element of preorder is root
        int rootValue = preorder[preIndex];
        preIndex++;

        // Create root
        TreeNode* root = new TreeNode(rootValue);

        // Find root in inorder
        int mid = inStart;

        while (inorder[mid] != rootValue) {
            mid++;
        }

        // Build left subtree
        root->left = buildTreeHelper(
            preorder,
            inorder,
            inStart,
            mid - 1
        );

        // Build right subtree
        root->right = buildTreeHelper(
            preorder,
            inorder,
            mid + 1,
            inEnd
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        return buildTreeHelper(
            preorder,
            inorder,
            0,
            inorder.size() - 1
        );
    }
};