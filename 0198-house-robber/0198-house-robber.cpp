class Solution {
public:
    // int fun(int ind,vector<int>& nums,vector<int>& dp){
    //     //DO IN TABULATION AND SPACE OPTIMISATION METHOD
    //     if(ind==0) return nums[ind];
    //     if(ind<0) return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //     int pick=nums[ind]+fun(ind-2,nums,dp);
    //     int not_pick=fun(ind-1,nums,dp);

    //     return dp[ind]=max(pick,not_pick);
    // }

    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev1=0,prev2=0,curr=0;
        vector<int> dp(n,0);
        prev1=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int not_pick=prev1;
            curr=max(pick,not_pick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};