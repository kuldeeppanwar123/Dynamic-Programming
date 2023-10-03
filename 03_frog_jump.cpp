RECURSION:
    time : O(2^N)
    space : O(N)
    code :
    int helper(int idx , vector<int>&heights){
      if(idx==0)return 0;

      int oneStep = helper(idx-1 , heights)+abs(heights[idx]-heights[idx-1]);
      int twoStep = INT_MAX;
      if(idx>1){
        twoStep = helper(idx-2 , heights)+abs(heights[idx]-heights[idx-2]);
       }
      return min(oneStep , twoStep);
    }
    int frogJump(int n, vector<int> &heights)
    {
      return helper(n-1, heights,dp);
    } 

---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(N)
      space : O(2N)
      code : 
        int helper(int idx , vector<int>&heights,vector<int>&dp){
          if(idx==0)return 0;

          if(dp[idx]!=-1)return dp[idx];
          int oneStep = helper(idx-1 , heights,dp)+abs(heights[idx]-heights[idx-1]);
          int twoStep = INT_MAX;
          if(idx>1){
             twoStep = helper(idx-2 , heights,dp)+abs(heights[idx]-heights[idx-2]);
           }
          return dp[idx] =  min(oneStep , twoStep);
       }

       int frogJump(int n, vector<int> &heights)
       {
           vector<int>dp(n,-1);
           return helper(n-1, heights,dp);
       } 
  
---------------------------------------------------------------------------------

TABULATION:
    time : O(N)
    space : O(N)
    code : 
      int frogJump(int n, vector<int> &heights)
      {
        vector<int>dp(n);
        dp[0] = 0;
        if(n==1)return dp[0];
        dp[1] = abs(heights[1]-heights[0]);
    
        for(int i=2; i<n; i++){
          int oneStep = dp[i-1]+abs(heights[i]-heights[i-1]);
          int twoStep = dp[i-2]+abs(heights[i]-heights[i-2]);
          dp[i] = min(oneStep,twoStep);
        }
        return dp[n-1];
       }

--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O(N)
    space : O(1)
    code : 
        int frogJump(int n, vector<int> &heights)
        {
           int prev1 = 0;
           int prev2 = abs(heights[1]-heights[0]);
    
           for(int i=2; i<n; i++){
               int oneStep = prev2+abs(heights[i]-heights[i-1]);
               int twoStep = prev1+abs(heights[i]-heights[i-2]);
               int curr = min(oneStep , twoStep);
               prev1 = prev2;
               prev2 = curr;
             }
             return prev2;
         }

    -------------------------------------------------------------------------------------------
