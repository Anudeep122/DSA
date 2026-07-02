class Solution {
public:

    int fun(int ind,int k,vector<int>& nums){
        
        if(ind==0){
            if(k==0 && nums[0]==0) return 2;
            if(k==0 || k==nums[0]) return 1;
            else return 0;
        }
        
        int not_pick=fun(ind-1,k,nums);
        int pick=0;
        if(nums[ind]<=k) pick=fun(ind-1,k-nums[ind],nums);
        return pick+not_pick;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum-target<0 || (sum-target)%2!=0) return 0;
        return fun(n-1,(sum-target)/2,nums);
    }
};