# 1262.可被三整除的最大和

[题目描述](https://leetcode-cn.com/problems/greatest-sum-divisible-by-three/)

# 思路

动态规划

思路比较明显  

状态定义:  
dp[i][j]  num   
i为当前所决策的数num的索引值  
j为求和后模3的值  
num为当前数  

状态转移方程:  
dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j - num)(mod 3)] + num)

边界条件:  
dp[0][0] = 0
dp[0][1] = INT_MIN
dp[0][2] = INT_MIN
dp[0][num%3] = num
