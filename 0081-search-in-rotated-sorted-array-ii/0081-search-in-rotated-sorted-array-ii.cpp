class Solution {
public:
    bool search(vector<int>& v, int k) {
        int n=v.size();
        int lo=0,hi=n-1,ans=0;
        while(lo<hi && v[lo]==v[hi])lo++;
        int x = lo;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(v[mid]<v[x])hi = mid-1;
            else {
                ans = mid;
                lo=mid+1;
            }
        }
        
        if(ans==n-1 && x!=0)ans = x-1;
        
        lo=0,hi=n-1;
        if(k>=v[0] && k<=v[ans])hi=ans;
        else lo = ans+1;

        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(v[mid]==k)return true;
            else if(v[mid]<k)lo=mid+1;
            else hi = mid-1;
        }

        return false;
    }
};