class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxdis=0;
        int cur=0,n=nums.size();
        while(cur<=maxdis && cur<n)
        {
            maxdis=max(maxdis,cur+nums[cur]);
            cur++;
        }
        return maxdis>=n-1;
    }
};