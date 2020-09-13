class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(3,0));
        dp[0][0]=0;
        dp[0][1]=INT_MIN;
        dp[0][2]=INT_MIN;
        dp[0][nums[0]%3]=nums[0];
        for(int i=1;i<n;i++)
        {
            int temp=nums[i]%3;
            if(temp==0)
            {
                dp[i][0]=max(dp[i-1][0],dp[i-1][0]+nums[i]);
                dp[i][1]=max(dp[i-1][1],dp[i-1][1]+nums[i]);
                dp[i][2]=max(dp[i-1][2],dp[i-1][2]+nums[i]);
            }
            else if(temp==1)
            {
                dp[i][0]=max(dp[i-1][0],dp[i-1][2]+nums[i]);
                dp[i][1]=max(dp[i-1][1],dp[i-1][0]+nums[i]);
                dp[i][2]=max(dp[i-1][2],dp[i-1][1]+nums[i]);
            }
            else if(temp==2)
            {
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]+nums[i]);
                dp[i][1]=max(dp[i-1][1],dp[i-1][2]+nums[i]);
                dp[i][2]=max(dp[i-1][2],dp[i-1][0]+nums[i]);
            }
        }
        return dp[n-1][0]==INT_MIN?0:dp[n-1][0];
    }
};