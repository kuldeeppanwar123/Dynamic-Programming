RECURSION:
    time : O(2^N)
    space : O(N)
    code :
int helper(int idx , int cap ,vector<int>&weight, vector<int>&value){
	if(idx<0)return 0;
	if(cap==0)return 0;
      
	int notTake = helper(idx-1,cap,weight,value);
	int take = INT_MIN;
	if(weight[idx]<=cap){
		take = helper(idx-1,cap-weight[idx],weight,value)+value[idx];
	}
	return dp[idx][cap] = max(take,notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return helper(n-1,maxWeight,weight,value);
}


    


---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(N*maxWeight)
      space : O(N*maxWeight)+O(N)
      code : 

int helper(int idx , int cap ,vector<int>&weight, vector<int>&value ,vector<vector<int>>&dp ){
	if(idx<0)return 0;
	if(cap==0)return 0;
	if(dp[idx][cap]!=-1)return dp[idx][cap];

	int notTake = helper(idx-1,cap,weight,value,dp);
	int take = INT_MIN;
	if(weight[idx]<=cap){
		take = helper(idx-1,cap-weight[idx],weight,value,dp)+value[idx];
	}
	return dp[idx][cap] = max(take,notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	return helper(n-1,maxWeight,weight,value,dp);
}

    
---------------------------------------------------------------------------------

TABULATION:
      time : O(N*target)
      space : O(N*target)
    code : 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
	for(int i=1;i<maxWeight+1;i++){
		if(weight[0]<=i)dp[0][i] = value[0];
	}
	for(int idx=1;idx<n; idx++){
		for(int w=1;w<maxWeight+1;w++){
			int notTake = dp[idx-1][w];
			int take = 0;
			if(weight[idx]<=w)
			take = dp[idx-1][w-weight[idx]]+value[idx];

			dp[idx][w] = max(notTake , take);
		}
	}
	return dp[n-1][maxWeight];

}

--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O(n*maxweight)
    space : O(2*maxweight)
    code : 
  
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int>curr(maxWeight+1,0),prev(maxWeight+1,0);

	for(int i=weight[0];i<maxWeight+1;i++)curr[i] = value[0];
	
	for(int idx=1;idx<n; idx++){
		swap(prev,curr);
		for(int w=1;w<maxWeight+1;w++){
			int notTake = prev[w];
			int take = 0;
			if(weight[idx]<=w)
			take = prev[w-weight[idx]]+value[idx];

			curr[w] = max(notTake , take);
		}
	}
	return curr[maxWeight];

}

 -------------------------------------------------------------------------------------------
