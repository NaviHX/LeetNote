class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        solve(root);
        reverse(ans.begin(),ans.end());
        return ans;
    }
private:
    vector<vector<int>> ans;
    void solve(TreeNode* root){
        ans.push_back(*(new vector<int>));
        dfs(root, 0);
    }
    void dfs(TreeNode* node,int level){
        if(node==NULL) return;
        if(level>=ans.size())
            ans.push_back(*(new vector<int>));
        ans[level].push_back(node->val);
        dfs(node->left,level+1);
        dfs(node->right,level+1);
        return;
    }
};