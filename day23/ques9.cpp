#include <bits/stdc++.h> 
void dfs(vector<int> graph[],stack<int> &st,int vertex,vector<int> &visited)
{
    visited[vertex]=1;
    for(auto child:graph[vertex])
    {
        if(visited[child])
        continue;
        dfs(graph,st,child,visited);
    }
    st.push(vertex);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
   vector<int> graph[v];
    for(auto it:edges)
    {
        int u=it[0];
        int v=it[1];
        graph[u].push_back(v);
       
    }
   stack<int> st;
   vector<int> visited(v,0);
    for(int i=0;i<v;i++)
	    {
	        if(visited[i]==0)
	        {
	            dfs(graph,st,i,visited);
	        }
	    }
   
   vector<int> ans;
   while(!st.empty())
   {
       ans.push_back(st.top());
       st.pop();
   }
   return ans;

}