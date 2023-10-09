RECURSION:
    time : O(2^(m*n))
    space : O(m+n)
    code :

    int helper(int row , int col ,int m ,int n){
        if(row==m-1 && col==n-1)return 1;
        if(row==m || col==n)return 0;

        int count=0;
        count+=helper(row+1,col,m,n);
        count+=helper(row ,col+1,m,n);
        return count;
    }
    int uniquePaths(int m, int n) {
        return helper(0,0,m,n);
    }


---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(m*n)
      space : O((m*n)+(m+n))
    //   m*n for dp array and m+n for recursive call
      code : 
      int helper(int row , int col ,int m ,int n,vector<vector<int>>&dp){
        if(row==m-1 && col==n-1)return 1;
        if(row==m || col==n)return 0;
        if(dp[row][col]!=-1)return dp[row][col];

        int count=0;
        count+=helper(row+1,col,m,n,dp);
        count+=helper(row ,col+1,m,n,dp);
        return dp[row][col] = count;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1 ,-1));
        return helper(0,0,m,n,dp);
    }


---------------------------------------------------------------------------------

TABULATION:
    time : O(M*N)
    space : O(M*N)
    code : int uniquePaths(int m, int n) {
        int dp[m][n];

        for(int row = m-1; row>=0; row--){
            for(int col =n-1; col>=0; col--){
                if(row==m-1 || col==n-1){
                    dp[row][col]=1;
                    continue;
                }
                dp[row][col] = dp[row+1][col]+dp[row][col+1];
            }
        }
        return dp[0][0];
    }


--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O(M*N)
    space : O(N)
    code : 
    int uniquePaths(int m, int n) {
        vector<int>dp(n , 1);
        for(int row=m-2; row>=0; row--){
            for(int col=n-2; col>=0; col--){
                dp[col] = dp[col]+dp[col+1];
            }
        }
        return dp[0];        
    }
       

 -------------------------------------------------------------------------------------------
