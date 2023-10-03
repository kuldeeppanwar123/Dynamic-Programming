RECURSION:
    time : O(2^N)
    space : O(N)
    code :
    int climbStairs(int n) {
        if(n<=2)return n;
        return climbStairs(n-1)+climbStairs(n-2);
    }

---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(N)
      space : O(2N)
      code : 
        int helper(int n, vector<int>&dp){
          if(n<0)return 0;
          if(n==0)return 1;

          if(dp[n]!=-1)return dp[n];
          dp[n] = helper(n-1,dp)+helper(n-2,dp);
          return dp[n];
        }

    int climbStairs(int n) {
        vector<int>dp(n+1 , -1);
        return helper(n , dp);
    }
  
---------------------------------------------------------------------------------

TABULATION:
    time : O(N)
    space : O(N)
    code : 
        int climbStairs(int n) {
          vector<int>dp(n+1 ,-1);
          dp[0] = 1;
          dp[1] = 1;
          for(int i=2; i<=n; i++){
              dp[i] = dp[i-1]+dp[i-2];
          }
          return dp[n];
       }

--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O(N)
    space : O(1)
    code : 
        int climbStairs(int n) {
        vector<int>dp(n+1 ,-1);
        int prev2 = 1;
        int prev1 = 1;
        for(int i=2; i<=n; i++){
            int curr = prev1+prev2;
            prev2=prev1;
            prev1 = curr;
        }
        return prev1;
    }

    -------------------------------------------------------------------------------------------
