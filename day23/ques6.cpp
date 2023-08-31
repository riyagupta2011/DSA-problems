bool dfs(vector<int> graph[],int vertex,vector<int> &visited,vector<int> &dfsvisited)
{
  visited[vertex]=1;
  dfsvisited[vertex]=1;
  for(auto child:graph[vertex])
  {
    if(!visited[child])
    {
      if(dfs(graph,child,visited,dfsvisited))
      return true;
    }
    else if(dfsvisited[child])
    {
      return true;
    }
  }
  dfsvisited[vertex]=0;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<int> graph[n+1];
  for(auto it:edges)
  {
    int u=it.first;
    int v=it.second;
    graph[u].push_back(v);
    
  }
  vector<int> visited(n+1,0);
  vector<int> dfsvisited(n+1,0);
  for(int i=1;i<=n;i++)
  {
    if(visited[i]!=1)
    {
       if(dfs(graph,i,visited,dfsvisited))
       return 1;
    }
   
  }
  return 0;
}