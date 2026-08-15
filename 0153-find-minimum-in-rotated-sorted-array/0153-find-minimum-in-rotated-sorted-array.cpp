class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1,ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]<nums[0]) high=mid-1;
            else{
                ans=mid;
                low=mid+1;
            }
        }
        if(ans==n-1) return nums[0];
        else return nums[ans+1];
    }
};