class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        for(int i=0;i<n;i++)
        {
            edge.push_back(*(new vector<int>));
            visited.push_back(false);
        }
            
        for(int i=0;i<graph.size();i++)
            edge[graph[i][0]].push_back(graph[i][1]);
        q.push(start);
        visited[start]=true;
        while(!q.empty())
        {
            int s=q.front();
            visited[s]=true;
            for(int i=0;i<edge[s].size();i++)
                if(!visited[edge[s][i]])
                    q.push(edge[s][i]);
            if(visited[target])
                break;
            q.pop();
        }
        return visited[target];
    }
private:
    queue<int> q;
    vector<bool> visited;
    vector<vector<int>> edge;
};