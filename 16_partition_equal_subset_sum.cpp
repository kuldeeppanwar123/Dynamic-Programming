RECURSION:
    time : O(2^N)
    space : O(N)
    code :

class Solution {
public:
    bool helper(int idx, int sum1 , int sum2,vector<int>&v){
        if(idx==0){
            return (sum1+v[0]==sum2 || sum1 == sum2+v[0]);
        }
        bool left = helper(idx-1,sum1+v[idx],sum2,v);
        bool right = helper(idx-1,sum1,sum2+v[idx],v);

        return left||right;
    }
    bool canPartition(vector<int>& nums) {
        return helper(nums.size()-1,0,0,nums);
        
    }
};

    


---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(N*target)
      space : O(N*target)+O(N)
      code : 

class Solution {
public:
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
    bool canPartition(vector<int>& nums) {
    
        int sum = 0;
        for(int itm:nums){
            sum+=itm;
        }
        if(sum%2!=0)return false;
        return subsetSumToK(nums.size(),sum/2 ,nums);
        
    }
};
    
---------------------------------------------------------------------------------

TABULATION:
      time : O(N*target)
      space : O(N*target)
    code : 

    bool canPartition(vector<int>& arr) {
    
        int sum = 0;
        for(int itm:arr){
            sum+=itm;
        }
        if(sum%2!=0)return false;
        int n = arr.size();
        int k = sum/2;

        vector<vector<int>>dp(n,vector<int>(k+1,0));
  
        for(int idx=0; idx<n; idx++){
            dp[idx][0] =1;
        }

        if(arr[0]<=k)dp[0][arr[0]] = 1;

        for(int idx=1; idx<n; idx++){
            for(int target=1; target<=k; target++){
                bool notTake = dp[idx-1][target];
                bool take = false;
                if(arr[idx]<=target)
                take = dp[idx-1][target-arr[idx]];

                dp[idx][target] = notTake || take;
            }
        }

        return dp[n-1][k];
        
    }

--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O()
    space : O()
    code : 
       

 -------------------------------------------------------------------------------------------
