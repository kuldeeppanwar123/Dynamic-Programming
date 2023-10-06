RECURSION:
    time : O(N^2)
    space : O(N)
    code :
int helper(int n,int orignal){
        if(n==1)return 1;
        int maxi = (n==org)?0:n;
        for(int i=1; i<n; i++){
            int temp = helper(i,orignal)*helper(n-i,orignal);
            maxi = max(maxi,temp);
        }
        return maxi;
    }
    int integerBreak(int n) {
        return helper(n,n);
    }
---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(N^2)
      space : O(2N)
      code : 
int helper(int n,int org,vector<int>&dp){
        if(n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        int maxi = (n==org)?0:n;
        for(int i=1; i<n; i++){
            int temp = helper(i,org,dp)*helper(n-i,org,dp);
            maxi = max(maxi,temp);
        }
        return dp[n] = maxi;
    }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,n,dp);
    }

---------------------------------------------------------------------------------

TABULATION:
    time : O(N)
    space : O(N)
    code : 
int integerBreak(int n) {
        vector<int>dp(n+1);
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            int maxi = (i==n)?0:i;
            for(int j=1; j<i; j++){
                int temp = dp[j]*dp[i-j];
                maxi = max(maxi, temp);
            }
            dp[i] = maxi;
        }
        return dp[n];
    }

--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O()
    space : O()
    code : 
        not possible

 -------------------------------------------------------------------------------------------
