SAME AS 5TH BUT IN CIRCULAR WAY.EITHER PICK FIRST OF LAST.

int maxNonAdjValue(vector<int>nums){
        int prev1 = nums[0];
        int prev2,curr;

        for(int i=1; i<nums.size(); i++){
            int include = nums[i];
            if(i-2>=0)include+=prev2;
            int exclude = prev1;

            curr = max(include , exclude);
            prev2=prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int>temp1 , temp2;

        for(int i=0; i<n; i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }

        int excludeFirst = maxNonAdjValue(temp1);
        int excludeLast = maxNonAdjValue(temp2);

        return max(excludeFirst,excludeLast);
    }
