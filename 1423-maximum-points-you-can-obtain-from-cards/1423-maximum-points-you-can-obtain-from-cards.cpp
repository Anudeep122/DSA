class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n=arr.size();
        int ans=0;
        int lsum=0,rsum=0;
        for(int i=0;i<k;i++){
            lsum+=arr[i];
        }
        ans=lsum;int j=n-1;
        for(int i=k-1;i>=0;i--){
            lsum=lsum-arr[i];
            rsum=rsum+arr[j];j--;
            ans=max(ans,lsum+rsum);
        }
        return ans;
    }
};