class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> distance(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        pq.push({0,S});
        distance[S]=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int dis=it.first;
            int u=it.second;
            
            for(auto child:adj[u])
            {
                int node=child[0];
                int wt=child[1];
                if(dis+wt<distance[node])
                {
                    distance[node]=dis+wt;
                    pq.push({distance[node],node});
                }
            }
        }
        return distance;
    }
};
