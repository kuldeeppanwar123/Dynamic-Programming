RECURSION:
    time : O(2^N)+more
    space : O(N)
    code :
    int helper(int idx, int amt , vector<int>&coins){

        if(amt==0)return 1;
        if(idx==0){
            if(amt%coins[0]==0)return 1;
            return 0;
        }

        int notTake = helper(idx-1,amt , coins);
        int take = 0;
        if(coins[idx]<=amt)
        take = helper(idx, amt-coins[idx],coins);

        return notTake+take;
    }
    int change(int amount, vector<int>& coins) {
        return helper(coins.size()-1,amount,coins);
    } 

---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(N*amount)
      space : O(N*amount)+O(N)
      code : 

       int helper(int idx, int amt , vector<int>&coins,vector<vector<int>>&dp){

        if(amt==0)return 1;
        if(idx==0){
            if(amt%coins[0]==0)return 1;
            return 0;
        }

        if(dp[idx][amt]!=-1)return dp[idx][amt];
        int notTake = helper(idx-1,amt , coins,dp);
        int take = 0;
        if(coins[idx]<=amt)
        take = helper(idx, amt-coins[idx],coins,dp);

        return dp[idx][amt] =  notTake+take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(coins.size()-1,amount,coins,dp);
    }


    
---------------------------------------------------------------------------------

TABULATION:
      time : O(N*amount)
      space : O(N*amount)
    code : 
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        
        for(int amt=0 ; amt<=amount; amt++){
            if(amt%coins[0]==0)dp[0][amt]=1;
        }

        for(int idx=1 ;idx<n; idx++){
            for(int amt = 0; amt<=amount; amt++){
                int notTake = dp[idx-1][amt];
                int take = 0;
                if(coins[idx]<=amt)
                take = dp[idx][amt-coins[idx]];
                dp[idx][amt] =  notTake+take;
            }
        }
        return dp[n-1][amount];
        
    }



--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O(n*amount)
    space : O(2*maxweight)
    code : 
     int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int>curr(amount+1,0),prev(amount+1,0);
        curr[0]=1;
        for(int amt=0 ; amt<=amount; amt++){
            if(amt%coins[0]==0)curr[amt]=1;
        }
       

        for(int idx=1 ;idx<n; idx++){
            swap(curr,prev);
            curr[0]=1;
            for(int amt = 1; amt<=amount; amt++){
                int notTake = prev[amt];
                int take = 0;
                if(coins[idx]<=amt)
                take = curr[amt-coins[idx]];
                curr[amt] =  notTake+take;
            }
        }

        return curr[amount];
        
    }

 -------------------------------------------------------------------------------------------
