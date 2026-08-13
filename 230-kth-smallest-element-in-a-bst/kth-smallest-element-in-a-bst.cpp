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

    void inorder(TreeNode* root, int& k, int& answer) {

        if (root == nullptr) {
            return;
        }

        // 1. Go to left subtree
        inorder(root->left, k, answer);

        // 2. Visit current node
        k--;

        // 3. If k becomes 0, this is the kth smallest
        if (k == 0) {
            answer = root->val;
            return;
        }

        // 4. Go to right subtree
        inorder(root->right, k, answer);
    }

    int kthSmallest(TreeNode* root, int k) {

        int answer = -1;

        inorder(root, k, answer);

        return answer;
    }
};