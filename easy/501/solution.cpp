class Solution
{
public:
    vector<int> findMode(TreeNode *root)
    {
        if(root==NULL)
            return vector<int>(0,0);
        dfs(root);
        return ans;
    }
private:
    vector<int> ans;
    int ans_counter = 0;
    int temp_counter = 0;
    int pre=-0x7fffffff;
    void dfs(TreeNode* node)
    {
        if(node==NULL)
            return;
        dfs(node->left);
        check_ans(node);
        dfs(node->right);
    }
    void check_ans(TreeNode* node)
    {
        if(node->val==pre)
            temp_counter++;
        else
        {
            temp_counter = 1;
            pre = node->val;
        }
        if(ans_counter<temp_counter)
        {
            ans_counter = temp_counter;
            ans.erase(ans.begin(), ans.end());
            ans.push_back(node->val);
        }
        else if(ans_counter==temp_counter)
            ans.push_back(node->val);
    }
};