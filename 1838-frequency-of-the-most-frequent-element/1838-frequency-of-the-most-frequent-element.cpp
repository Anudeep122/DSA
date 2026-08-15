class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        nums.insert(nums.begin(),0);
        sort(nums.begin(),nums.end());
        vector<long int> ps(n+1,0);
        for(int i=1;i<=n;i++){
            ps[i]=ps[i-1]+nums[i];
        }
        long int l=1,r=1,ans=0;
        while(r<=n){
            long int x=nums[r]*(r-l+1);
            long int req=x-(ps[r]-ps[l-1]);
            while(req>k){
                l++;
                x=nums[r]*(r-l+1);
                req=x-(ps[r]-ps[l-1]);
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return (int)ans;
        
    }
};