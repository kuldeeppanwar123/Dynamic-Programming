RECURSION:
    time : O(2^N)
    space : O(N)
    code :

bool helper(int idx , int target , vector<int>&arr){
    if(target==0)return true;
    if(idx==0)return arr[0]==target;

    bool ex = helper(idx-1,target,arr);
    bool in = false;
    if(arr[idx]<=target){
        in = helper(idx-1,target-arr[idx],arr);
    }
    return ex || in;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return helper(n-1,k,arr);
}


int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    return helper(0,0,c-1,r,c,grid);
}

    


---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(N*target)
      space : O(N*target)+O(N)
      code : 
bool helper(int idx , int target , vector<int>&arr,vector<vector<int>>&dp){
    if(target==0)return true;
    if(idx==0)return arr[0]==target;
    if(dp[idx][target]!=-1)return dp[idx][target];
    bool ex = helper(idx-1,target,arr,dp);
    if(ex)return true;
    bool in = false;
    if(arr[idx]<=target){
        in = helper(idx-1,target-arr[idx],arr,dp);
    }
    return dp[idx][target] = ex || in;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
  vector<vector<int>>dp(n+1 , vector<int>(k+1,-1));
    return helper(n-1,k,arr,dp);
}
    
---------------------------------------------------------------------------------

TABULATION:
    time : O()
    space : O()
    code : 

--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O()
    space : O()
    code : 
       

 -------------------------------------------------------------------------------------------
