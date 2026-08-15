class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       int n=nums.size();
       int low=0,high=n-1;
       int ans=0;
       while(low<=high){
        int mid=(low+high)/2;
        
        if(mid%2==0){
            if(mid!=n-1 && nums[mid]==nums[mid+1]) low=mid+1;
            else {ans=mid;high=mid-1;}
        }
        else{
            if(nums[mid]==nums[mid-1] ) low=mid+1;
            else {ans=mid;high=mid-1;}
        }
       }
       return nums[ans];
    }
};