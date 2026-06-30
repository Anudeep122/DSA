class Solution {
public:
    int fun(int ind,vector<int>& nums,vector<int>& dp){
        //DO IN TABULATION AND SPACE OPTIMISATION METHOD
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind]+fun(ind-2,nums,dp);
        int not_pick=fun(ind-1,nums,dp);

        return dp[ind]=max(pick,not_pick);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=dp[i-2];
            int not_pick=dp[i-1];
            dp[i]=max(pick,not_pick);
        }
        return dp[n-1];
    }
};