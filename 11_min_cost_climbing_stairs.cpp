RECURSION:
    time : O(2^N)
    space : O(N)
    code :

    int helper(int idx,vector<int>&cost){
        int size = cost.size();
        if(idx == size)return 0;
        if(idx==size-1)return cost[idx];

        int oneStep = helper(idx+1 , cost);
        int twoStep = helper(idx+2 , cost);

        if(idx==-1)
        return min(oneStep , twoStep);

        return min(oneStep, twoStep)+cost[idx];

    }
    int minCostClimbingStairs(vector<int>& cost) {
        return helper(-1,cost);
    }

    


---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(N)
      space : O(N+N)
    //   for dp array size N and N for recursive call stack
      code : 
    int helper(int idx,vector<int>&cost,vector<int>&dp){
        int size = cost.size();
        if(idx == size)return 0;
        if(idx==size-1)return cost[idx];
        if(idx>=0 && dp[idx]!=-1)return dp[idx];

        int oneStep = helper(idx+1 , cost,dp);
        int twoStep = helper(idx+2 , cost,dp);

        if(idx==-1)
        return min(oneStep , twoStep);

        return dp[idx] = min(oneStep, twoStep)+cost[idx];

    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size() , -1);
        return helper(-1,cost,dp);
    }


---------------------------------------------------------------------------------

TABULATION:
    time : O(N)
    space : O(N)
    code : 
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        int dp[size];
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2; i<size; i++){
            dp[i] = min(dp[i-1], dp[i-2])+cost[i];
        }
        return min(dp[size-1] , dp[size-2]);

    }


--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O(N)
    space : O(1)
    code : 
   int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i=2; i<size; i++){
            int curr = min(prev1, prev2)+cost[i];
            prev2 = prev1;
            prev1 = curr;

        }
        return min(prev2 , prev1);

    }
       

 -------------------------------------------------------------------------------------------
