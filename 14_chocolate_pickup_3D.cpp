RECURSION:
    time : O(3^N*3^N)
    space : O(N)
    code :

int helper(int row, int col1, int col2,int r,int c ,vector<vector<int>> &v ){
    if(col1<0 || col1>c-1 || col2<0 || col2>c-1)return -1e8;
    if(row==r-1){
        if(col1==col2)return v[row][col1];
        else return v[row][col2]+v[row][col1];
    }

    int ans = -1e8;
    for(int i=col1-1;i<=col1+1; i++){
        int left = helper(row+1,i,col2-1,r,c,v);
        int midd = helper(row+1,i,col2,r,c,v);
        int right = helper(row+1,i,col2+1,r,c,v);

        ans = max(max(left,midd),max(ans,right));
    }
    if(col2==col1)
    return ans+v[row][col1];
    else
    return ans+v[row][col1]+v[row][col2];
}


int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    return helper(0,0,c-1,r,c,grid);
}

    


---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(N*N+3)
      space : O(N*M*M+N)
      code : 
int helper(int row, int col1, int col2,int r,int c ,vector<vector<int>> &v, vector<vector<vector<int>>>&dp ){
    if(col1<0 || col1>c-1 || col2<0 || col2>c-1)return -1e8;
    if(row==r-1){
        if(col1==col2)return v[row][col1];
        else return v[row][col2]+v[row][col1];
    }

    if(dp[row][col1][col2]!=-1)return dp[row][col1][col2];
    int ans = -1e8;
    for(int i=col1-1;i<=col1+1; i++){
        int left = helper(row+1,i,col2-1,r,c,v,dp);
        int midd = helper(row+1,i,col2,r,c,v,dp);
        int right = helper(row+1,i,col2+1,r,c,v,dp);

       ans = max(max(left,midd),max(ans,right));
    }
    if(col2==col1)
     return dp[row][col1][col2] = ans+v[row][col1];
    else
     return dp[row][col1][col2]=ans+v[row][col1]+v[row][col2];
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return helper(0,0,c-1,r,c,grid,dp);
}
    
---------------------------------------------------------------------------------

TABULATION:
    time : O()
    space : O()
    code : 

--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O()
    space : O()
    code : 
       

 -------------------------------------------------------------------------------------------
