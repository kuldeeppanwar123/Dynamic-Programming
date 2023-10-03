RECURSION:
    time : O(k^N)
    space : O(N)
    code :
int helper(int idx , int k , vector<int>&height){
    if(idx==0)return 0;

    int ans = INT_MAX;

    for(int i=1;i<=k; i++){
         int temp=INT_MAX;
         if(idx>=i)
         temp = helper(idx-i,k,height)+abs(height[idx]-height[idx-i]);
         ans = min(ans, temp);
    }
    return ans;
}
int minimizeCost(int n, int k, vector<int> &height){
    return helper(n-1,k,height);
}
---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(N*k)
      space : O(2N)
      code : 
int helper(int idx , int k , vector<int>&height,vector<int>&dp){
    if(idx==0)return 0;
    if(dp[idx]!=-1)return dp[idx];
    int ans = INT_MAX;

    for(int i=1;i<=k; i++){
         int temp=INT_MAX;
         if(idx>=i)
         temp = helper(idx-i,k,height,dp)+abs(height[idx]-height[idx-i]);
         ans = min(ans, temp);
    }
    return dp[idx] = ans;
}
int minimizeCost(int n, int k, vector<int> &height){
    vector<int>dp(n,-1);
    return helper(n-1,k,height,dp);
}

---------------------------------------------------------------------------------

TABULATION:
    time : O(N*k)
    space : O(N)
    code : 
int minimizeCost(int n, int k, vector<int> &height){
    vector<int>dp(n,-1);
    
    dp[0] = 0;
    for(int i=1; i<n; i++){
        int ans = INT_MAX;
        for(int j=1; j<=k; j++){
            int temp = INT_MAX;
            if(i-j>=0){
                temp = dp[i-j]+abs(height[i]-height[i-j]);
            }
            ans = min(temp , ans);
        }
        dp[i] = ans;
    }
    return dp[n-1];
}

--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O(N)
    space : O(k)
    code : 
       space can't be constant.
       space can be reduced till k.
       in worst case when k=n space complexity remain O(N)
       
 -------------------------------------------------------------------------------------------
