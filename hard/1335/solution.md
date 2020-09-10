# 1335.工作计划的最低难度

[题目描述](https://leetcode-cn.com/problems/minimum-difficulty-of-a-job-schedule/)

# 思路

动态规划

状态定义 : dp[i][j]  
第i天完成前j项工作的最低难度  

边界 :  
dp[0]都是前缀的最大值

转移方程 :  
dp[i][j] = min{dp[i - 1][k] + [k, j]间难度最大值}  
k代表当日从第k项工作开始
其中, j >= i, i<= k<= j (因为限制了每天至少完成一项工作)