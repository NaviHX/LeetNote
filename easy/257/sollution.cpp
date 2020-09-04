/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL)
            return ans;
        dfs(root,"");
        return ans;
    }
private:
    vector<string> ans;
    void dfs(TreeNode* root,string pre)
    {
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(pre+to_string(root->val));
            return ;
        }
        else
        {
            pre=pre+to_string(root->val)+"->";
            if(root->left!=NULL) dfs(root->left,pre);
            if(root->right!=NULL) dfs(root->right,pre);
            return ;
        }
    }
};