class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(); //row
        int n = grid[0].size(); //column
        int ans =0;
        for(int i =0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 1)
                { ans+=4; 
                     
                 
                   if( i+1 <m  && grid[i+1][j] == 1  )  // if down neighbour is there
                   {        ans--;}
                 if(   i-1 >=0 && grid[i-1][j] == 1 ) // if upward neighbour is there
                 { ans--;}
                   if(   j-1>=0  && grid[i][j-1] == 1)  // if left neighbour is there
                   {     ans--;}
                 if(  j+1<n && grid[i][j+1] == 1 ) // if right neighbour is there
                 { ans--;}
                }
            }
        }
        return ans;
    }
};


// simple without dfs
// add 4 for every node and remove 2 for every edge