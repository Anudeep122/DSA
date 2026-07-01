class Solution {
public:
    bool fun(int ind,int k,vector<int>& nums,vector<vector<int>>& dp){
        if(k==0) return true;
        if(ind==0) return (nums[0]==k);
        if(dp[ind][k]!=-1) return dp[ind][k];
        bool not_take=fun(ind-1,k,nums,dp);
        bool take=false;
        if(nums[ind]<=k) take=fun(ind-1,k-nums[ind],nums,dp);
        return dp[ind][k]=take|not_take; 
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        vector<vector<int>> dp(n,vector<int> ((sum/2)+1,-1));
        // cout<<sum;
        if(sum%2!=0) return false;
        else return fun(n-1,sum/2,nums,dp);
    }
};