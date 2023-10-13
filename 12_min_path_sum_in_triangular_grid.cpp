RECURSION:
    time : O(2^N*N)
    space : O(N)
    code :

    int helper(int row,int col, vector<vector<int>>&v){
        if(row==v.size()-1)
        return v[row][col];

        int first = helper(row+1,col,v);
        int second = helper(row+1,col+1, v);

        return min(first,second)+v[row][col];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return helper(0,0,triangle);
    }

    


---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(N*N)
      space : O(N*N+N)
    //   for dp array size N and N for recursive call stack
      code : 
   int helper(int row,int col, vector<vector<int>>&v, vector<vector<int>>&dp){
        if(row==v.size()-1)
        return v[row][col];

        if(dp[row][col]!=-1)return dp[row][col];

        int first = helper(row+1,col,v,dp);
        int second = helper(row+1,col+1, v,dp);

        return dp[row][col] = min(first,second)+v[row][col];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n-1,vector<int>(n-1,-1));
        return helper(0,0,triangle,dp);
    }


---------------------------------------------------------------------------------

TABULATION:
    time : O(N*N)
    space : O(N*N)
    code : 
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int dp[n][n];

        for(int col = 0; col<n; col++){
            dp[n-1][col] = triangle[n-1][col];
        }

        for(int row=n-2; row>=0; row--){
            for(int col=0; col<=row; col++){
                dp[row][col] = min(dp[row+1][col],dp[row+1][col+1])+triangle[row][col];
            }
        }
        return dp[0][0];
    }


--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O(N*N)
    space : O(N)
    code : 
   int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int dp[n];

        for(int i=0; i<n; i++){
            dp[i] = triangle[n-1][i];
        }

        for(int row = n-2; row>=0; row--){
            for(int col=0; col<=row;col++){
                dp[col] = min(dp[col] , dp[col+1])+triangle[row][col];
            }
        }
        return dp[0];
    }
       

 -------------------------------------------------------------------------------------------
