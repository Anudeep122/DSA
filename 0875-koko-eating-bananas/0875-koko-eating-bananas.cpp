class Solution {
public:
    long long int sum(vector<int>& piles,long long int mid){
        int n=piles.size();
        long long int cnt=0;
        for(int i=0;i<n;i++){
            if(piles[i]%mid==0) cnt=cnt+(piles[i]/mid);
            else cnt=cnt+(piles[i]/mid)+1;
        }
        return cnt;
    }

    int minEatingSpeed(vector<int>& piles,int h) {
        int n=piles.size();
        long long int low=1,high=INT_MAX;
        long long int ans=0;
        while(low<=high){
            long long int mid=low+(high-low)/2;
            if(sum(piles,mid)<=h){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};