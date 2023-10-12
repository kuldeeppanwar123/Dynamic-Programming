1RECURSION:
    time : O(2^(m*n))
    space : O(m+n)
    code :

int helper(int row ,int col, vector<vector<int>>&grid){
        if(row==0 && col==0)return grid[row][col];
        if(row<0 || col<0)return INT_MAX;

        int left = helper(row , col-1, grid);
        int right = helper(row-1 , col, grid);

        return min(left ,right)+grid[row][col];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        return helper(row-1, col-1,grid);
    }

    


---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(m*n)
      space : O((m*n)+(m+n))
    //   m*n for dp array and m+n for recursive call
      code : 
     int helper(int row ,int col, vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(row==0 && col==0)return grid[row][col];
        if(row<0 || col<0)return INT_MAX;
        if(dp[row][col]!=-1)return dp[row][col];

        int left = helper(row , col-1, grid,dp);
        int right = helper(row-1 , col, grid,dp);

        return dp[row][col] = min(left ,right)+grid[row][col];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        return helper(row-1, col-1,grid,dp);
    }


---------------------------------------------------------------------------------

TABULATION:
    time : O(M*N)
    space : O(M*N)
    code : 
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m,vector<int>(n));
        dp[0][0]=grid[0][0];

        for(int row=0; row<m; row++){
            if(row==0){
                for(int col=1; col<n; col++){
                    dp[row][col] =dp[row][col-1]+grid[row][col];
                }
            }
            else{
                for(int col=0; col<n; col++){
                    if(col==0){
                        dp[row][col]=dp[row-1][col]+grid[row][col];
                        continue;
                    }
                    dp[row][col]=min(dp[row-1][col] , dp[row][col-1])+grid[row][col];
                }
            }
        }
        return dp[m-1][n-1];
        
    }


--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O(M*N)
    space : O(N)
    code : 
   int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

       int dp[n];
        dp[0] = grid[0][0];
        for(int col=1; col<n; col++){
            dp[col] = dp[col-1]+grid[0][col];
        }

        for(int row=1; row<m; row++){
            for(int col=0; col<n; col++){
                if(col==0){
                    dp[col]+=grid[row][col];
                }
                else{
                    dp[col] = min(dp[col],dp[col-1])+grid[row][col];
                }
            }
        }
        return dp[n-1];
        
    }
       

 -------------------------------------------------------------------------------------------
