RECURSION:
    time : O(2^(m*n))
    space : O(m+n)
    code :

int helper(int row ,int col , vector<vector<int>>&v){
       
        if(row==0 && col==0)return 1;
        if(row<0 || col<0)return 0;
         if(v[row][col]==1)return 0;

        int left = helper(row , col-1, v);
        int up = helper(row-1,col,v);
        return left +up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1)return 0;
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        return helper(row-1,col-1,obstacleGrid);
    }
    


---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(m*n)
      space : O((m*n)+(m+n))
    //   m*n for dp array and m+n for recursive call
      code : 
     int helper(int row ,int col , vector<vector<int>>&v,vector<vector<int>>&dp){
       
        if(row==0 && col==0)return 1;
        if(row<0 || col<0)return 0;
         if(v[row][col]==1)return 0;
         if(dp[row][col]!=-1)return dp[row][col];

        int left = helper(row , col-1, v,dp);
        int up = helper(row-1,col,v,dp);
        return dp[row][col] = left +up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1)return 0;
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));

        return helper(row-1,col-1,obstacleGrid,dp);
    }


---------------------------------------------------------------------------------

TABULATION:
    time : O(M*N)
    space : O(M*N)
    code : 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];
        if(obstacleGrid[m-1][n-1]==1)return 0;

        for(int row = 0; row<m; row++){
            for(int col =0; col<n; col++){
                if(obstacleGrid[row][col]==1){
                    dp[row][col] = 0;
                    
                }
                else if(row==0 && col==0){
                    dp[row][col]=1;
                }
                else{
                    int up=0,left=0;
                    if(row>0)up = dp[row-1][col];
                    if(col>0)left = dp[row][col-1];
                    dp[row][col] = up+left;
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
   
       

 -------------------------------------------------------------------------------------------
