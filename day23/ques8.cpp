class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> graph[]) 
	{
	    // code here
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:graph[i])
	        {
	            indegree[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    vector<int> ans;
	    while(!q.empty())
	    {
	        int vertex=q.front();
	        q.pop();
	        ans.push_back(vertex);
	        for(auto child:graph[vertex])
	        {
	            indegree[child]--;
	            if(indegree[child]==0)
	            q.push(child);
	        }
	    }
	    return ans;
	}
};