class Solution {
public:
   void dfs(vector<vector<int>>& image, int i, int j, int color,int c)
   {
       cout<<i<<j<<endl;
       if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=c )
       return ;
       image[i][j]=color;
       dfs(image,i+1,j,color,c);
       dfs(image,i,j+1,color,c);
       dfs(image,i-1,j,color,c);
       dfs(image,i,j-1,color,c);
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int c=image[sr][sc];
       if(c==color)
       return image;
         dfs(image,sr,sc,color,c);
         return image;
    }
};