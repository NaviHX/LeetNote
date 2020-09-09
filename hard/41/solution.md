# 41.缺失的第一个正数

[题目描述](https://leetcode-cn.com/problems/first-missing-positive/)

# 思路

要求时间复杂度O(n),空间复杂度O(1)

答案一定是位于[1,n+1]的整数,只需要检查[1,n]的整数是否出现  
将所有非正数换作n+1  
原地哈希表:  
数组中出现过的数字位置上的数换成负数  
即:  
出现过nums[i],nums[nums[i]]换做负数  
找到最小出现正数的位置即可
