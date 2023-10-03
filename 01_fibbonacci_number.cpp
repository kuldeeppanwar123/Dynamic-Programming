RECURSION:
    time : O(2^N)
    space : O(N)
    code :
       int f(int n){
           if(n<=1) return n;
           return f(n-1) + f(n-2);
       }

----------------------------------------------------------------------------------
MEMOIZATION : 
      time : O(N)
      space : O(2N)
      code : 
           int f(int n,vector<int>&dp){
               if(n<=1) return n;
               if(dp[n]!=-1)return dp[n];
      
               return dp[n] = f(n-1,dp) + f(n-2,dp);
           }
  
----------------------------------------------------------------------------------------

TABULATION:
    time : O(N)
    space : O(N)
    code : 
        int main() {
          int n=5;
          vector<int> dp(n+1,-1);
  
          dp[0]= 0;
          dp[1]= 1;
  
         for(int i=2; i<=n; i++){
             dp[i] = dp[i-1]+ dp[i-2];
         }
          cout<<dp[n];
          return 0;
        }

----------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O(N)
    space : O(1)
    code : 
        int main() {
            int n=5;
  
            int prev2 = 0;
            int prev = 1;
  
            for(int i=2; i<=n; i++){
                int cur_i = prev2+ prev;
                prev2 = prev;
                prev= cur_i;
            }
            cout<<prev;
            return 0;
          }
