class DisjointSet{
    public:
    vector<int> parent;
    vector<int> size;
    vector<int> rank;
    
    DisjointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++)
        parent[i]=i;
        
    }
    int findParent(int node)
    {
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionBySize(int u,int v)
    {
        int up=parent[u];
        int uv=parent[v];
        if(up==uv)
        return ;
        if(rank[up]<rank[uv])
        {
            parent[up]=uv;
        }
        else if(rank[uv]<rank[up])
        {
            parent[uv]=up;
        }
        else
        {
             parent[uv]=up;
             rank[up]++;
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                int v=it[0];
                int wt=it[1];
                edges.push_back({wt,{i,v}});
                
            }
        }
        int sum=0;
        sort(edges.begin(),edges.end());
        DisjointSet ds(V);
        for(auto it:edges)
        {
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.findParent(u)!=ds.findParent(v))
            {
                sum=sum+wt;
                ds.unionBySize(u,v);
                
            }
        }
        return sum;
    }
};