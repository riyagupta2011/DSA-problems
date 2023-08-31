class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        q.push(0);
        vector<int> ans;
        vector<int> visited(V,0);
        visited[0]=1;
        while(!q.empty())
        {
            int vertex=q.front();
            q.pop();
            
            ans.push_back(vertex);
            for(auto child:adj[vertex])
            {
                if(visited[child])
                continue;
                visited[child]=1;
                q.push(child);
            }
        }
        return ans;
    }
};