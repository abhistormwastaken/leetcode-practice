class Solution {
    public:
        int minFlips(vector<vector<int>>& grid) {
            int flipsx = 0, flipsy = 0;
            int n = grid.size(), m = grid[0].size();
            for(int i = 0; i < n / 2; i++){
                for(int j = 0; j < m; j++){
                    if(grid[i][j] != grid[n - i - 1][j]){
                        flipsx++;
                    }
                }
            }
            for(int j = 0; j < m / 2; j++){
                for(int i = 0; i < n; i++){
                    if(grid[i][j] != grid[i][m - j - 1]){
                        flipsy++;
                    }
                }
            }
            return min(flipsx, flipsy);
        }
    };