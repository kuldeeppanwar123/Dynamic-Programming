RECURSION:
    time : O(2^N)+more
    space : O(N)
    code :
int helper(int idx, int n , vector<int>&price){
	if(idx==1)
	return price[0]*n;

	int notTake = helper(idx-1, n , price);
	int take = 0;
	if(idx<=n)
	take = helper(idx , n-idx,price)+price[idx-1];

	return max(notTake,take);
}
int cutRod(vector<int> &price, int n)
{
	
	return helper(n,n,price);

}



---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(N*N)
      space : O(N*N)+O(N)
      code : 

int helper(int idx, int n , vector<int>&price,vector<vector<int>>&dp){

	if(idx==1)
	return price[0]*n;

	if(dp[idx][n]!=-1)return dp[idx][n];

	int notTake = helper(idx-1, n , price,dp);
	int take = 0;
	if(idx<=n)
	take = helper(idx , n-idx,price,dp)+price[idx-1];

	return dp[idx][n] = max(notTake,take);
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n+1,vector<int>(n+1,-1));	
	return helper(n,n,price,dp);

}

       

    
---------------------------------------------------------------------------------

TABULATION:
      time : O(N*N)
      space : O(N*N)
    code : 

 
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n,vector<int>(n+1,0));
	for(int N=0; N<=n; N++){
		dp[0][N] = N*price[0];
	}	

	for(int idx = 1; idx<n; idx++){
		for(int N=0; N<=n; N++){
			int notTake = dp[idx-1][N];
			int take = 0;
			int rodlen = idx+1;
			if(rodlen<=N)
			take = dp[idx][N-rodlen]+price[idx];
			dp[idx][N] = max(notTake,take);
		}
	}
	return dp[n-1][n];

}




--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O(n*cap)
    space : O(2*cap)
    code : 


int cutRod(vector<int> &price, int n)
{
	vector<int>curr(n+1,0),prev(n+1,0);
	for(int N=0; N<=n; N++){
		curr[N] = N*price[0];
	}	

	for(int idx = 1; idx<n; idx++){
		swap(curr , prev);
		for(int N=0; N<=n; N++){
			int notTake = prev[N];
			int take = 0;
			int rodlen = idx+1;
			if(rodlen<=N)
			take = curr[N-rodlen]+price[idx];
			curr[N] = max(notTake,take);
		}
	}
	return curr[n];

}
  

 -------------------------------------------------------------------------------------------
