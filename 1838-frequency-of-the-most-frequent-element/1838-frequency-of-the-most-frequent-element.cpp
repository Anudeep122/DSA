class Solution {
public:
    bool chk(vector<int>& v,int k,int mid){
        int n=v.size();
        long int sum = 0;
        for(int i=0;i<mid;i++){
            sum += (long)v[i];
        }

        int l=0,r=mid-1;
        if((long)mid*(long)v[r]-sum <=k)return true;

        while(r+1<n){
            r++;
            sum += v[r]-v[l];
            if((long)mid*(long)v[r]-sum<=k)return true;
            l++;
        }

        return false;
    }

    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int lo=1,hi=n,ans=0;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(chk(nums,k,mid)){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }

        return ans;
    }
};