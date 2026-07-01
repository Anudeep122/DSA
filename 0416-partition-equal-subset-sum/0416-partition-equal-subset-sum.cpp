class Solution {
public:
    // bool fun(int ind,int k,vector<int>& nums,vector<vector<int>>& dp){
    //     if(k==0) return true;
    //     if(ind==0) return (nums[0]==k);
    //     if(dp[ind][k]!=-1) return dp[ind][k];
    //     bool not_take=fun(ind-1,k,nums,dp);
    //     bool take=false;
    //     if(nums[ind]<=k) take=fun(ind-1,k-nums[ind],nums,dp);
    //     return dp[ind][k]=take|not_take; 
    // }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int target=sum/2;
        vector<vector<bool>> dp(n,vector<bool> (target+1,false));
        // cout<<sum;
        if(sum%2!=0) return false;
        vector<bool> prev(target+1,0),curr(target+1,0);
        prev[0]=true;curr[0]=true;
        if(nums[0] <= target)
            prev[nums[0]] = true;

        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool not_take=prev[j];
                bool take=false;
                if(nums[i]<=j) take=prev[j-nums[i]];
                curr[j]=take|not_take;
            }
            prev=curr;
        }
        return prev[target];
    }
};