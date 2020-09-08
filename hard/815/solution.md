# 815.公交路线

[题目描述](https://leetcode-cn.com/problems/bus-routes/)

# 思路

最短路径

很容易想到这是一道求最短路的题目,但是直接套最短路模板会超时

观察一下根据题目构建来的图,我们可以发现:  
1.在一条路线中各站点移动是不会多乘车的,也就是说一条路线内各点的边权重为0  
2.不同路线切换时,乘车数+1  

利用1,2两点性质,我们可以将一整条路线看作一个点,拥有相同站点的两各路线'点'之间连有一个权重为1的边,在进行求最短路径即可

# 提示

## 建图

很容易想到依次遍历各路线的点,找到相同的点后建边的方法  
但是当路线内点数过多的情况下,效率堪忧  

利用双指针建图

首先对所有路线内点排序,对每两个路线双指针法找相同点  
因为点数单调,判断大小后只需移动相应的指针
```c++
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                int p1=0,p2=0;
                while(p1<routes[i].size() && p2<routes[j].size())
                {
                    if(routes[i][p1]==routes[j][p2])
                    {
                        edge[i].push_back(j);
                        edge[j].push_back(i);
                        break;
                    }
                    else if(routes[i][p1]>routes[j][p2])
                        p2++;
                    else
                        p1++;
                }
            }
```

# 求最短路

因为所有边权值为1,所以直接BFS就行了

复习一下可以求最短路的算法

## Bellman-Ford:
动态规划的思路  
N个点遍历所有边N次  
```c++
for(int i=0;i<N;i++)
    for(int j=0;j<edge.size();j++)
    {
        //松弛操作
    }
```

## SPFA
```c++
queue<int> q;
dis[src]=0;
while(!q.empty())
{
    int now=q.front();
    for(int i=0;i<edge[now].size();i++)
    {
        //松弛操作
        //更新dis值后新点入队
    }
}
```

## Dijkstra
贪心思想  
每次取出U中最短点加入S,更新U中路径值  
```c++
priority_queue<node> q;//路径长度的小根堆,包含所有点,因为起点路径是0所以第一个一定是起点
while(!q.empty())
{
    node now=q.front();
    q.pop();
    for( ... )
    {
        //更新
        //更新点入堆
    }
}
```
