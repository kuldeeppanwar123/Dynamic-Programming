RECURSION:
    time : O()
    space : O()
    code :

  


--------------------------------------------------------------------------------------------------------

MEMOIZATION : 
      time : O()
      space : O()
      code : 
 
       

    
-------------------------------------------------------------------------------------------------------

TABULATION:
      time : O(N*M)
      space : O(N*M)
    code : 
    
   int longestCommonSubstr (string str1, string str2, int n, int m)
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int ans = 0;
        for(int i=0;i<n; i++){
            for(int j=0; j<m; j++){
                if(str1[i]==str2[j]){
                    dp[i+1][j+1] = dp[i][j]+1;
                    ans = max(ans, dp[i+1][j+1]);
                }
            }
        }
        return ans;
     }

--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O(n*m)
    space : O(2*m)
    code : 
  int longestCommonSubstr (string str1, string str2, int n, int m)
    {
       vector<int>curr(m+1,0),prev(m+1,0);
        int ans = 0;
        for(int i=0;i<n; i++){
            swap(curr,prev);
            curr.assign(m+1,0);
            for(int j=0; j<m; j++){
                if(str1[i]==str2[j]){
                    curr[j+1] = prev[j]+1;
                    ans = max(ans, curr[j+1]);
                }
            }
        }
        return ans;
    }


  

 ------------------------------------------------------------------------------------------------------
