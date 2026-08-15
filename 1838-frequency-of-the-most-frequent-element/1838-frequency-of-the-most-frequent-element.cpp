class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        nums.insert(nums.begin(),0);
        sort(nums.begin(),nums.end());

        vector<long long> v(n+1,0);
        for(int i=1;i<=n;i++){
            v[i] = v[i-1]+nums[i];
        }

        long long l=1,r=1;
        int ans = 1;
        while(r<=n){
            long long x = (r-l+1)*nums[r];
            long long req = x - (v[r]-v[l-1]);

            while(req>k){
                l++;
                x = (r-l+1)*nums[r];
                req = x - (v[r]-v[l-1]);
            }

            if(r-l+1>ans)ans = r-l+1;
            r++;
        }

        return ans;
    }
};