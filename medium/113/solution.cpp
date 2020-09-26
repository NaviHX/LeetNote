class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return vector<vector<int>>(0, vector<int>(0, 0));
        vector<int> arr;
        dfs(root, arr, 0, sum);
        return ans;
    }

private:
    vector<vector<int>> ans;
    void dfs(TreeNode *node, vector<int> &arr, int sum, int goal)
    {
        arr.push_back(node->val);
        sum += node->val;
        if (node->left)
            dfs(node->left, arr, sum, goal);
        if (node->right)
            dfs(node->right, arr, sum, goal);
        else if (!node->left && !node->right && sum == goal)
            ans.push_back(arr);
        arr.pop_back();
        sum -= node->val;
    }
};