class Solution {
public:
    long long int sum(vector<int>& nums,long long int mid){
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]%mid==0) cnt=cnt+(nums[i]/mid);
            else cnt=cnt+(nums[i]/mid)+1;
        }
        return cnt;
    }

    int smallestDivisor(vector<int>& nums, int k) {
        int n=nums.size();
        long long int low=1,high=INT_MAX;
        long long int ans=0;
        while(low<=high){
            long long int mid=low+(high-low)/2;
            if(sum(nums,mid)<=k){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};