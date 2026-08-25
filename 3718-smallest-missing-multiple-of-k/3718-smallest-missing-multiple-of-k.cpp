class Solution {
public:
    bool fun(vector<int>& nums, int ans){
        int n=nums.size();
        int low=0,high=n-1;
        sort(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==ans) return true;
            else if(nums[mid]<ans) low=mid+1;
            else high=mid-1;
        }
        return false;
    }

    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=k;int i=2;
        while(fun(nums,ans)==true){
            ans=k*i;
            i++;
        }
        return ans;
    }
};