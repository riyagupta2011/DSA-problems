class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int> &visited,vector<int> adj[],vector<int> &ans,int vertex)
    {
        visited[vertex]=1;
        ans.push_back(vertex);
        for(auto child:adj[vertex])
        {
            if(visited[child])
            continue;
            dfs(visited,adj,ans,child);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> visited(V,0);
        dfs(visited,adj,ans,0);
        return ans;
    }
};
