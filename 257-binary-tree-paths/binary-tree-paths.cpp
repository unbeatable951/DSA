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

    void treePath(TreeNode* root,string path,vector<string>&ans)
    {
        if(root==nullptr)
        {
            return;
        }
        path += to_string(root->val);

        if(root->left==nullptr && root->right==nullptr)
        {
            ans.push_back(path);
            return;
        }

        path +="->";

        treePath(root->left,path,ans);
        treePath(root->right,path,ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;

        treePath(root,"",ans);
        return ans;
    }
};