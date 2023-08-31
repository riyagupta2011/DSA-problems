
class Solution {
public:
bool dfs(vector<vector<int>>& graph,vector<int> &color,int node,vector<int> &visited,int c)
{
    color[node]=c;
    for(auto child:graph[node])
    {
        if(color[child]==-1)
        {
            if(!dfs(graph,color,child,visited,!c))
            return false;
        }
        
        else if(color[child]==c)
        return false;

    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        vector<int> visited(n,0);
       
        for(int i=0;i<n;i++)
        {
           if(color[i]==-1)
           {
              if(!dfs(graph,color,i,visited,0))
              return false;
           }
          
        }
        return true;
    }
};