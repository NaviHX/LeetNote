#define INF (0x7fffffff-1001)
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d) return -1;
        vector<vector<int>> dp(d,vector<int>(n,INF));
        int m=0;
        for(int i=0;i<n;i++)
        {
            m=max(m,jobDifficulty[i]);
            dp[0][i]=m;
        }
        for(int i=1;i<d;i++)
        {
            for(int j=i;j<n;j++)
            {
                m=jobDifficulty[j];
                for(int k=j-1;k>=i-1;k--)
                {
                    m=max(m,jobDifficulty[k+1]);
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+m);
                }
            }
        }
        return dp[d-1][n-1];
    }
};