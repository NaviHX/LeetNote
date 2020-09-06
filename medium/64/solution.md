# 64.最小路径和

[题目描述](https://leetcode-cn.com/problems/minimum-path-sum/)
相似题目:[剑指offer47.礼物的最大价值](https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/)

# 思路

动态规划

先处理上边和左边的网格

中间的网格状态转移方程:

```
dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
```
