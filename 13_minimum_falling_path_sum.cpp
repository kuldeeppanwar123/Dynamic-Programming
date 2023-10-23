RECURSION:
    time : O(2^N)
    space : O(N)
    code :

       int helper(int row , int col ,vector<vector<int>>&matrix){
        if(col<0 || col>matrix.size()-1)return INT_MAX;
        if(row==0)return matrix[row][col];

        int left = helper(row-1,col-1,matrix);
        int midd = helper(row-1, col,matrix);
        int right = helper(row-1,col+1,matrix); 

        int ans  = min(min(left, midd),right)+matrix[row][col];
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        for(int col = 0; col<n; col++){
            int temp = helper(n-1,col,matrix);
            ans = min(temp, ans);
        }
        return ans;
    }

    


---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(N*N)
      space : O(N*N+N)
    int helper(int row , int col ,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(col<0 || col>matrix.size()-1)return INT_MAX;
        if(row==0)return matrix[row][col];
        if(dp[row][col]!=-1)return dp[row][col];

        int left = helper(row-1,col-1,matrix,dp);
        int midd = helper(row-1, col,matrix,dp);
        int right = helper(row-1,col+1,matrix,dp); 

        int ans  = min(min(left, midd),right)+matrix[row][col];
        return dp[row][col]  =  ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans = INT_MAX;
        for(int col = 0; col<n; col++){
            int temp = helper(n-1,col,matrix,dp);
            ans = min(temp, ans);
        }
        return ans;
    }

---------------------------------------------------------------------------------

TABULATION:
    time : O(N*N)
    space : O(N*N)
    code : 
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        for(int col=0; col<n; col++){
            dp[0][col] = matrix[0][col];
        }

        for(int row=1; row<n; row++){
            for(int col=0; col<n; col++){
                int left = INT_MAX;
                int mid = INT_MAX;
                int right = INT_MAX;

                if(col!=0)left = dp[row-1][col-1];
                mid = dp[row-1][col];
                if(col!=(n-1))right = dp[row-1][col+1];

                dp[row][col] = min(left,min(mid,right))+matrix[row][col];
            }
        }

        int ans = INT_MAX;
        for(int col = 0; col<n; col++){
            ans = min(ans, dp[n-1][col]);
        }
        return ans;
    }


--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O(N*N)
    space : O(N)
    code : 
   int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>curr(n),prev(n);

        for(int col=0; col<n; col++){
            curr[col] = matrix[0][col];
        }

        for(int row=1; row<n; row++){
            swap(curr,prev);
            for(int col=0; col<n; col++){
                int left = INT_MAX;
                int mid = INT_MAX;
                int right = INT_MAX;

                if(col!=0)left = prev[col-1];
                mid = prev[col];
                if(col!=(n-1))right = prev[col+1];

                curr[col] = min(left,min(mid,right))+matrix[row][col];
            }
        }

        int ans = INT_MAX;
        for(int col = 0; col<n; col++){
            ans = min(ans, curr[col]);
        }
        return ans;
    }
       

 -------------------------------------------------------------------------------------------
