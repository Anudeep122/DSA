class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int n=nums.size();
        int ans=0,mx=0;
        int zeros=0;

        while(l<n && r<n){
            if(nums[r]==0){
                zeros++;   
            }
            if(zeros<=k) ans=r-l+1;
            else {
                while(zeros>k){
                    if(nums[l]==0) zeros--;
                    l++; 
                }
            }


            mx=max(mx,ans);
            r++;
        }
        return mx;
    }
};