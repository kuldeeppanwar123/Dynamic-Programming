RECURSION:
    time : O(2^N)+more
    space : O(N+M)
    code :

    int helper(int idx1, int idx2 , string s1 , string s2){
        if(idx1==-1 || idx2==-1)return 0;

        if(s1[idx1]==s2[idx2])
        return 1+helper(idx1-1,idx2-1,s1,s2);

        int first = helper(idx1-1, idx2,s1,s2);
        int second = helper(idx1,idx2-1,s1,s2);

        return max(first ,second);
    }
    int longestCommonSubsequence(string text1, string text2) {
        return helper(text1.size()-1,text2.size()-1,text1,text2);
    }



---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(N*M)
      space : O(N*M)+O(N+M)
      code : 

      int f(int i, int j , string a, string b,vector<vector<int>>&dp){
        if(i<0 || j <0)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if(a[i]==b[j])
        return dp[i][j] =  1+f(i-1,j-1,a,b,dp);
        else
        return dp[i][j] = max(f(i,j-1,a,b,dp),f(i-1,j,a,b,dp));

    }
    int longestCommonSubsequence(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,a,b,dp);
    }

       

    
---------------------------------------------------------------------------------

TABULATION:
      time : O(N*M)
      space : O(N*M)
    code : 

      int longestCommonSubsequence(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(a[i-1]==b[j-1])
                  dp[i][j] =  1+dp[i-1][j-1];
                else
                  dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][m];

              
    }


--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O(n*m)
    space : O(2*m)
    code : 

    int longestCommonSubsequence(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<int>curr(m+1,0),prev(m+1,0);
        for(int i=1; i<=n; i++){
            swap(curr,prev);
            for(int j=1; j<=m; j++){
                if(a[i-1]==b[j-1])
                  curr[j] =  1+prev[j-1];
                else
                  curr[j] = max(curr[j-1],prev[j]);
            }
        }
        return curr[m];
              
    }


  

 -------------------------------------------------------------------------------------------
