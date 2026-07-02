class Solution {
public:

    int fun(int ind,int k,vector<int>& nums){
        if(ind==0){
            if(k==nums[0] && k==-nums[0]) return 2;
            else if(k==nums[0] || k==-nums[0]) return 1;
            else return 0;
        }

        int add=fun(ind-1,k-nums[ind],nums);
        int sub=fun(ind-1,k+nums[ind],nums);
        return add+sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return fun(n-1,target,nums);
    }
};