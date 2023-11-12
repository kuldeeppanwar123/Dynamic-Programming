RECURSION:
    time : O(2^N)+more
    space : O(N)
    code :
    
int helper(int idx, int cap ,vector<int> &profit, vector<int> &weight){

    if(idx==0){
        if(cap%weight[0]==0)
        return profit[0]*cap/weight[0];
        return 0;
    }
    int notTake = helper(idx-1 ,cap , profit , weight);
    int take = 0;
    if(weight[idx]<=cap){
        take = helper(idx , cap-weight[idx],profit , weight)+profit[idx];
    }

    return max(notTake , take);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    return helper(n-1 , w , profit , weight);
}

---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(N*cap)
      space : O(N*cap)+O(N)
      code : 

  
int helper(int idx, int cap ,vector<int> &profit, vector<int> &weight,vector<vector<int>>&dp){

    if(idx==0){
        if(cap%weight[0]==0)
        return profit[0]*cap/weight[0];
        return 0;
    }
    if(dp[idx][cap]!=-1)return dp[idx][cap];
    int notTake = helper(idx-1 ,cap , profit , weight,dp);
    int take = 0;
    if(weight[idx]<=cap){
        take = helper(idx , cap-weight[idx],profit , weight,dp)+profit[idx];
    }

    return dp[idx][cap] =  max(notTake , take);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>>dp(n,vector<int>(w+1,-1));
    return helper(n-1 , w , profit , weight,dp);
}

       

    
---------------------------------------------------------------------------------

TABULATION:
      time : O(N*cap)
      space : O(N*cap)
    code : 


int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>>dp(n,vector<int>(w+1,0));
    
    for(int cap =0; cap<=w; cap++){
         if(cap%weight[0]==0)
         dp[0][cap] =  profit[0]*cap/weight[0];
    }

    for(int idx =1; idx<n; idx++){
        for(int cap=1; cap<=w; cap++){
                
                int notTake = dp[idx-1][cap];
                int take = 0;
                if(weight[idx]<=cap){
                    take = dp[idx][cap-weight[idx]]+profit[idx];
                }
                dp[idx][cap] =  max(notTake , take);
             }
         }
    return dp[n-1][w];
}
   



--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O(n*cap)
    space : O(2*cap)
    code : 


int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){

    vector<int>curr(w+1,0),prev(w+1,0);
    for(int cap =0; cap<=w; cap++){
         if(cap%weight[0]==0)
         curr[cap] =  profit[0]*cap/weight[0];
    }

    for(int idx =1; idx<n; idx++){
        swap(curr ,prev);
        for(int cap=1; cap<=w; cap++){
                int notTake = prev[cap];
                int take = 0;
                if(weight[idx]<=cap){
                    take = curr[cap-weight[idx]]+profit[idx];
                }
                curr[cap] =  max(notTake , take);
             }
         }
    return curr[w];
}     

 -------------------------------------------------------------------------------------------
