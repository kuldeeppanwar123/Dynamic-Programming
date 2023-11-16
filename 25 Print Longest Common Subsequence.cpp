RECURSION:
    time : O(2^N)+more
    space : O(N+M)
    code :

  string f(int i , int j , string a ,string b){

	if(i<0 || j<0)return "";

	if(a[i]==b[j])
		return dp[i][j] = f(i-1,j-1, a,b)+a[i];

	else{
		string first = f(i-1,j,a,b);
		string second = f(i,j-1,a,b);
	    return  (first.size()>second.size())?first:second;
	}
}
string findLCS(int n, int m,string &s1, string &s2){
	return f(n-1,m-1,s1,s2);
}


--------------------------------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(N*M)
      space : O(N*M)+O(N+M)
      code : 
string f(int i , int j , string a ,string b,vector<vector<string>>&dp){

	if(i<0 || j<0)return "";

	if(dp[i][j]!="")return dp[i][j];
	if(a[i]==b[j])
		return dp[i][j] = f(i-1,j-1, a,b,dp)+a[i];

	else{
		string first = f(i-1,j,a,b,dp);
		string second = f(i,j-1,a,b,dp);
	    return dp[i][j] = (first.size()>second.size())?first:second;
	}
}
string findLCS(int n, int m,string &s1, string &s2){
	vector<vector<string>>dp(n+1,vector<string>(m+1,""));
	return f(n-1,m-1,s1,s2,dp);
}
 
       

    
-------------------------------------------------------------------------------------------------------

TABULATION:
      time : O(N*M)
      space : O(N*M)
    code : 

string findLCS(int n, int m,string &a, string &b){
	vector<vector<string>>dp(n+1,vector<string>(m+1,""));

	for(int i=1;i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[i-1]==b[j-1])
				dp[i][j] = dp[i-1][j-1]+a[i-1];

			else{
				string first =  dp[i-1][j];
				string second = dp[i][j-1];
				dp[i][j] = (first.size()>second.size())?first:second;
			}
		}
	}
	return dp[n][m];
}


--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O(n*m)
    space : O(2*m)
    code : 

string findLCS(int n, int m,string &a, string &b){
	vector<string>curr(m+1,""),prev(m+1,"");
	for(int i=1;i<=n; i++){
		swap(curr,prev);
		for(int j=1; j<=m; j++){
			if(a[i-1]==b[j-1])
				curr[j] = prev[j-1]+a[i-1];

			else{
				string first =  prev[j];
				string second = curr[j-1];
				curr[j] = (first.size()>second.size())?first:second;
			}
		}
	}
	return curr[m];
}
  

 ------------------------------------------------------------------------------------------------------
