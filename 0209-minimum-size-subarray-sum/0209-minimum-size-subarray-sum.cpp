class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),0);
        vector<int> ps(n+1,0);
        for(int i=1;i<=n;i++){
            ps[i]=ps[i-1]+nums[i];
        }
        int r=1,ans=n+1;
        while(r<=n){
            int req=ps[r]-target;
            auto x=upper_bound(ps.begin(),ps.end(),req);
            int l=x-ps.begin();
            if(l!=0){
                ans=min(ans,r-l+1);
            }
            r++;
        }
        if(ans==n+1) return 0;
        else return ans;
    }
};