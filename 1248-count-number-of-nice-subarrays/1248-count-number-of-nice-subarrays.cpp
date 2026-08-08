class Solution {
public:
    int fun(vector<int>& nums,int k){
        int l=0,r=0,odd=0,ans=0;
        if(k<0) return 0;
        while(r<nums.size()){
            if(nums[r]%2!=0) odd++;
            while(odd>k){
                if(nums[l]%2!=0){
                    odd--;
                }
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }
};