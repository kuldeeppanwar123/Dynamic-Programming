approach 1:

code:
 class Solution {
public:
    int helper(int i, int j , string&s,vector<vector<int>>&dp){
        if(i==j)return 1;
        if(i>j)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==s[j])
        return dp[i][j] = helper(i+1,j-1,s,dp)+2;

        else{
            int first  = helper(i+1,j,s,dp);
            int second = helper(i,j-1,s,dp);

            return dp[i][j] = max(first, second);
        }
    }
    int longestPalindromeSubseq(string s) {

        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(0,n-1,s,dp);
    }
};



---------------------------------------------------------------------------------------------------------------

Approach 2:
 by using longest common subsequence
(find longest common subsequence between string and its reverse)

code: 
class Solution {
public:
          int f(int i, int j , string&a, string&b,vector<vector<int>>&dp){
        if(i<0 || j <0)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if(a[i]==b[j])
        return dp[i][j] =  1+f(i-1,j-1,a,b,dp);
        else
        return dp[i][j] = max(f(i,j-1,a,b,dp),f(i-1,j,a,b,dp));

    }
    int longestCommonSubsequence(string&a, string&b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,a,b,dp);
    }

    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        return longestCommonSubsequence(s,rev);
    }
};
