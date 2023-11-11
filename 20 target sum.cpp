RECURSION:
    time : O(2^N)
    space : O(N)
    code :

class Solution {
public:
    int helper(int idx,int target,vector<int>&arr){

        if(idx==0){
              if(target-arr[0]==0 && target+arr[0]==0)return 2;
            if(target-arr[0]==0 || target+arr[0]==0)return 1;
            return 0;
        }

        int adding = helper(idx-1,target+arr[idx],arr);
        int minus = helper(idx-1,target-arr[idx],arr);

        return adding+minus;
    }

    int helper2(int idx,int sum1,int sum2,int diff, vector<int>&arr){

        if(idx==0){
            if(sum1+arr[0]-sum2==diff && sum1-(sum2+arr[0])==diff)return 2;
            if(sum1+arr[0]-sum2==diff || sum1-(sum2+arr[0])==diff)return 1;
            return 0;
        }
        int adding = helper2(idx-1,sum1+arr[idx],sum2,diff,arr);
        int minus = helper2(idx-1,sum1,sum2+arr[idx],diff,arr);

         return adding+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // return helper(nums.size()-1,target,nums);
        return helper2(nums.size()-1,0,0,target,nums);
    }
};

    


---------------------------------------------------------------------------------

MEMOIZATION : 
      time : O(N*amount)
      space : O(N*amount)+O(N)
      code : 


    
---------------------------------------------------------------------------------

TABULATION:
      time : O(N*amount)
      space : O(N*amount)
    code : 
    

--------------------------------------------------------------------------------------------------------

SPACE OPTIMIZATION:
    time : O(n*amount)
    space : O(2*amount)
    code : 
  
-------------------------------------------------------------
