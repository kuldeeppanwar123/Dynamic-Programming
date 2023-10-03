RECURSION:
    time : O(2^N)
    space : O(N)
    code :
int helper(int idx,vector<int>&v){
    if(idx==0)return v[0];
    if(idx<0)return 0;

   int includeSum = v[idx]+helper(idx-2,v);
   int excludeSum = 0+helper(idx-1,v);

    return max(includeSum,excludeSum);

  }
    int rob(vector<int>& nums) {
        return helper(nums.size()-1,nums);
    }
---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(N)
      space : O(2N)
      code : 
int helper(int idx,vector<int>&v,vector<int>&dp){
    if(idx==0)return v[0];
    if(idx<0)return 0;
    if(dp[idx]!=-1)return dp[idx];
    int includeSum = v[idx]+helper(idx-2,v,dp);
    int excludeSum = 0+helper(idx-1,v,dp);

    return dp[idx] = max(includeSum,excludeSum);

}
int rob(vector<int>& nums) {
    vector<int>dp(nums.size() , -1);
    return helper(nums.size()-1,nums,dp);
}

---------------------------------------------------------------------------------

TABULATION:
    time : O(N)
    space : O(N)
    code : 
int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n , -1);
        dp[0] = nums[0];
        

        for(int i=1; i<n; i++){
            int includeSum = nums[i];
            if(i-2>=0)includeSum+=dp[i-2];
            int excludeSum = dp[i-1];

            dp[i] = max(includeSum , excludeSum);
        }
        return dp[n-1];
    }

--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O(N)
    space : O(1)
    code : 
       int rob(vector<int>& nums) {
        int n= nums.size();
        int prev1 = nums[0];
        int prev2 ,curr;
        

        for(int i=1; i<n; i++){
            int includeSum = nums[i];
            if(i-2>=0)includeSum+=prev2;
            int excludeSum = prev1;

            curr = max(includeSum , excludeSum);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
 -------------------------------------------------------------------------------------------
