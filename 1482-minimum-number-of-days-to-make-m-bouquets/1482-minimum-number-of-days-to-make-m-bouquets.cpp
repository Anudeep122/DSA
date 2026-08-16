class Solution {
public:
    bool find(vector<int>& v,int m,int k,int mid){
        int n=v.size();
        int l=0;
        int x=k;
        while(l<n){
            if(m==0) return true;
            if(x!=0 && v[l]<=mid){
                x--;
            }
            else if(v[l]>mid){
                x = k;
            }

            if(x==0){
                x=k;m--;
            }
            l++;
        }

        if(m<=0)return true;
        return false;
    }

    int minDays(vector<int>& v, int m, int k) {
        int n=v.size();
        if(n<(long long)m*(long long)k) return -1;
        long long int low=1,high=INT_MAX,ans=0;
        while(low<=high){
            long long int mid=low+(high-low)/2;
            if(find(v,m,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};