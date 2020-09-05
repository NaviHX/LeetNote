# 787.K 站中转内最便宜的航班

[题目描述](https://leetcode-cn.com/problems/cheapest-flights-within-k-stops/)

# 思路

Bellman-Ford算法

该算法第一层遍历即可确定在K-2步情况下能前往的点的最短距离

限制第一层遍历次数为min(n,K-2)
