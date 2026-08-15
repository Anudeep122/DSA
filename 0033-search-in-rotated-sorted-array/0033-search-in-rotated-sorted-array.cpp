class Solution {
public:
    int search(vector<int>& v, int k) {
        int n=v.size();
        int lo=0,hi=n-1,ans;
        while(lo<=hi){
            int mid = (lo+hi);
            if(v[lo]<=v[mid] && v[mid]>=v[hi]){
                ans = mid;
                lo = mid+1;
            }
            else hi=mid-1;
        }
        cout<<ans;
        lo=0,hi=n-1;
        if(k>=v[0] && k<=v[ans])hi=ans;
        else lo = ans+1;

        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(v[mid]==k)return mid;
            else if(v[mid]<k)lo=mid+1;
            else hi = mid-1;
        }

        return -1;
    }
};