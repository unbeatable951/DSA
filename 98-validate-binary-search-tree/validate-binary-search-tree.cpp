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

    void inorder(TreeNode* root,vector<int>&res)
    {
        if(root==nullptr)
        {
            return;
        }
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>node;
        inorder(root,node);

        int n = node.size();

        for(size_t i=1;i<n;i++)
        {
            if(node[i]<=node[i-1])
            {
                return false;
            }
        }

        return true;
        
    }
};