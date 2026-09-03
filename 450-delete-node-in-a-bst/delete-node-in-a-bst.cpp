class Solution {
public:

    TreeNode* deleteNode(TreeNode* root, int key) {

        // Node not found
        if (root == nullptr)
            return nullptr;

        // Search in left subtree
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }

        // Search in right subtree
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        // We found the node
        else {

            // Case 1: No left child
            if (root->left == nullptr) {
                return root->right;
            }

            // Case 2: No right child
            if (root->right == nullptr) {
                return root->left;
            }

            // Case 3: Two children

            // Find inorder successor
            TreeNode* successor = root->right;

            while (successor->left != nullptr) {
                successor = successor->left;
            }

            // Copy successor's value
            root->val = successor->val;

            // Delete successor
            root->right = deleteNode(root->right, successor->val);
        }

        return root;
    }
};