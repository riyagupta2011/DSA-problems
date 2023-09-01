
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> visited(V,0);
        pq.push({0,0});
        int sum=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;
            if(visited[node]==1)
            continue;
            visited[node]=1;
            sum+=wt;
            for(auto it:adj[node])
            {
                int n=it[0];
                int w=it[1];
                if(!visited[n])
                pq.push({w,n});
            }
        }
        return sum;
    }
};