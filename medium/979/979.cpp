/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//  DFS 多余硬币向父节点传递,分配给空子节点,剩余硬币继续向上传递
// 优先遍历左子节点
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
private:
    int ans=0;
    int dfs(TreeNode* root) {
        if(root==NULL)
            return 0;
        int need=1-root->val;
        int left=dfs(root->left);
        int right=dfs(root->right);
        need+=left+right;
        ans+=abs(left)+abs(right);
        return need;
    }
};