class Solution {
public:
void dfs(vector<vector<int>> &visited,vector<vector<char>>& grid,int i,int j)
{
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()||grid[i][j]=='0'|| visited[i][j]==1)
    return;
    visited[i][j]=1;
    dfs(visited,grid,i+1,j);
    dfs(visited,grid,i-1,j);
    dfs(visited,grid,i,j+1);
    dfs(visited,grid,i,j-1);
}
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]!=1 && grid[i][j]=='1')
                {
                    dfs(visited,grid,i,j);
                    ans++;
                }
            }
        }
        return ans;

    }
};