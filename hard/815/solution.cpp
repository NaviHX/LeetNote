class Solution {
public:
    
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        vector<bool> visit;
        vector<vector<int>> edge;
        unordered_map<int,bool> ans;
        queue<int> q;
        if(S==T) return 0;
        int n=routes.size();
        edge.resize(n);
        for(int i=0;i<n;i++)
            sort(routes[i].begin(),routes[i].end());
        for(int i=0;i<n;i++)
            for(int j=0;j<routes[i].size();j++)
            {
                if(routes[i][j]==S) q.push(i);
                if(routes[i][j]==T) ans[i]=true;
            }
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
        int step=1;
        visit.resize(n,false);
        while(!q.empty())
        {
            int q_size=q.size();
            for(int i=0;i<q_size;i++)
            {
                int station=q.front();
                q.pop();
                if(visit[station]) continue;
                visit[station]=true;
                if(ans.count(station))
                    return step;
                for(int e=0;e<edge[station].size();e++)
                    if(visit[edge[station][e]]==false)
                        q.push(edge[station][e]);
            }
            step++;
        }
        return -1;
    }
};