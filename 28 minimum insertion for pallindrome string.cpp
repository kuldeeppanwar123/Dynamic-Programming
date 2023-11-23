Time - O(n*n)
space -O(N*N)+O(N)
code : 
int maxPallindromeLength(int low,int high,string&s,vector<vector<int>>&dp){
        if(low>high)return 0;
        if(low==high)return 1;
        if(dp[low][high]!=-1)return dp[low][high];

        if(s[low]==s[high])
        return dp[low][high] = 2+maxPallindromeLength(low+1,high-1,s,dp);
        else
        return dp[low][high] = max(maxPallindromeLength(low,high-1,s,dp),maxPallindromeLength(low+1,high,s,dp));
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int len = maxPallindromeLength(0,n-1,s,dp);
        return n-len;
    }
