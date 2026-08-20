class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        arr.insert(arr.begin(),0);
        int lo=1,hi=n;
        if(k<arr[1])return k;

        int ans = 0,rem = 0;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            int req = arr[mid]-mid;
            if(req<k){
                ans = mid;
                rem = k-req;
                lo = mid+1;
            }
            else hi = mid-1;
        }

        return arr[ans]+rem;
    }
};