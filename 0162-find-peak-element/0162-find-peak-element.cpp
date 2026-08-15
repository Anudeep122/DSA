class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int n=v.size();
        int low=0,high=n-1;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if((mid==0 || v[mid-1]<v[mid]) && (mid==n-1 || v[mid]>v[mid+1])) return mid;
            else if((mid==0 || v[mid-1]<=v[mid]) && (mid==n-1 || v[mid]<=v[mid+1])){
                low=mid+1;
            }
            else high=mid-1;
        }
        return 0;
    }
};