RECURSION:
    time : O(2^N)
    space : O(N)
    code :

 int helper(int idx,int target , vector<int>&arr){
	if(target==0)return 1;
	if(idx==0){
		return (arr[0]==target)?1:0;
	}


	int notTake = helper(idx-1,  target, arr);
	int take =0;
	if(target>=arr[idx])
	take = helper(idx-1, target-arr[idx], arr);

	return take+notTake;
}
int findWays(vector<int>& arr, int k)
{
	return helper(arr.size()-1, k, arr);
}


    


---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(N*target)
      space : O(N*target)+O(N)
      code : 

      int M = 1000000007;
      int helper(int idx,int target , vector<int>&arr , vector<vector<int>>&dp){
      	if(target==0)return 1;
      	if(idx==0){
      		return (arr[0]==target)?1:0;
      	}
      	if(dp[idx][target]!=-1)return dp[idx][target];
      
      	int notTake = helper(idx-1,  target, arr,dp);
      	int take =0;
      	if(target>=arr[idx])
      	take = helper(idx-1, target-arr[idx], arr,dp);
      
      	return dp[idx][target] =  (take+notTake)%M;
      }
      int findWays(vector<int>& arr, int k)
      {
      	vector<vector<int>>dp(arr.size() , vector<int>(k+1,-1));
      	return helper(arr.size()-1, k, arr, dp);
      }

    
---------------------------------------------------------------------------------

TABULATION:
      time : O(N*target)
      space : O(N*target)
    code : 

 int M = 1000000007;
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>>dp(n , vector<int>(k+1,0));

	for(int idx=0; idx<n; idx++){
		dp[idx][0] = 1;
	}

	if(arr[0]<=k)dp[0][arr[0]]=1;

	for(int idx=1; idx<n; idx++){
		for(int target =1; target<=k; target++){
			int notTake = dp[idx-1][target];
			int take =0;
			if(target>=arr[idx])
			take = dp[idx-1][target-arr[idx]];
	        dp[idx][target] =  (take+notTake)%M;
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
