RECURSION:
    time : O(2^N)
    space : O(N)
    code :
int helper(int idx,int amt , vector<int>&coins){
        if(idx==0){
            if(amt%coins[0]==0)return amt/coins[0];
            return 1e9;
        }

        int notTake = helper(idx-1,amt,coins);
        int take = INT_MAX;
        if(coins[idx]<=amt){
             take = helper(idx,amt-coins[idx],coins)+1;
        }
       
        return min(notTake,take);
    }


    int coinChange(vector<int>& coins, int amount) {
        int ans =  helper(coins.size()-1,amount,coins);
        return ans==1e9?-1:ans;
    }

    


---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(N*amount)
      space : O(N*amount)+O(N)
      code : 

int helper(int idx,int amt , vector<int>&coins,vector<vector<int>>&dp){
        if(idx==0){
            if(amt%coins[0]==0)return amt/coins[0];
            return 1e9;
        }
        if(dp[idx][amt]!=-1)return dp[idx][amt];

        int notTake = helper(idx-1,amt,coins,dp);
        int take = INT_MAX;
        if(coins[idx]<=amt){
             take = helper(idx,amt-coins[idx],coins,dp);
             if(take!=INT_MAX)take+=1;
        }
        return dp[idx][amt] = min(notTake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans =  helper(coins.size()-1,amount,coins,dp);
        return ans==1e9?-1:ans;
    }
    
---------------------------------------------------------------------------------

TABULATION:
      time : O(N*amount)
      space : O(N*amount)
    code : 
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int amt=0; amt<=amount; amt++){
            if(amt%coins[0]==0)dp[0][amt]=amt/coins[0];
            else
            dp[0][amt]=1e9;
        }

        for(int idx=1;idx<n;idx++){
            for(int amt=1;amt<=amount;amt++){
                int notTake = dp[idx-1][amt];
                int take = INT_MAX;
                if(coins[idx]<=amt){
                    take = dp[idx][amt-coins[idx]]+1;
                }
                dp[idx][amt] = min(take,notTake);
            }
        }
        return dp[n-1][amount]!=1e9?dp[n-1][amount]:-1;
    }

--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O(n*amount)
    space : O(2*amount)
    code : 
  
int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>prev(amount+1,0),curr(amount+1,0);
        for(int amt=0; amt<=amount; amt++){
            if(amt%coins[0]==0)curr[amt]=amt/coins[0];
            else
            curr[amt]=1e9;
        }

        for(int idx=1;idx<coins.size();idx++){
            swap(curr,prev);
            for(int amt=1;amt<=amount;amt++){
                int notTake = prev[amt];
                int take = 1e9;
                if(coins[idx]<=amt){
                    take = curr[amt-coins[idx]]+1;
                }
                curr[amt] = min(take,notTake);
            }
        }
        int ans = curr[amount];
        if(ans>=1e9)return -1;
        return ans;
    }

 -------------------------------------------------------------------------------------------
