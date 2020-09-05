#define INF 0x7fffffff
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<long> dp(n,INF);
        K=min(K,n-2);
        dp[src]=0;
        for(int i=0;i<=K;i++)
        {
            vector temp=dp;
            for(int j=0;j<flights.size();j++)
                temp[flights[j][1]]=min(temp[flights[j][1]],dp[flights[j][0]]+flights[j][2]);
            swap(temp,dp);
        }        
        return dp[dst]==INF?-1:dp[dst];
    }
};