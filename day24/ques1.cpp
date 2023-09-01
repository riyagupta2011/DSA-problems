#include <bits/stdc++.h>


void dfs(vector<int> graph[],stack<int> &st,int vertex,vector<int> &visited)
{
    visited[vertex]=1;
    for(auto child:graph[vertex])
    {
        if(!visited[child])
        dfs(graph,st,child,visited);
    }
    st.push(vertex);
}
void dfs2(int vertex,vector<int> &visited2,vector<int> graph2[],vector<int> &level)
{
    visited2[vertex]=1;
    level.push_back(vertex);
     for(auto child:graph2[vertex])
    {
        if(!visited2[child])
        dfs2(child,visited2,graph2,level);
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    stack<int> st;
    vector<int> graph[n];
    for(auto it:edges)
    {
        int u=it[0];
        int v=it[1];
        graph[u].push_back(v);
    }
    vector<int> visited(n,0);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        dfs(graph,st,i,visited);
    }
    vector<int> graph2[n];
    for(auto it:edges)
    {
        int u=it[0];
        int v=it[1];
        graph2[v].push_back(u);
    }
    vector<int> visited2(n,0);
    vector<vector<int>> ans;
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(!visited2[node])
        {
            vector<int> level;
            dfs2(node,visited2,graph2,level);
            ans.push_back(level);
        }
    }
    return ans;
    