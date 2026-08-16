class Solution {
public:
    long long int sum(vector<int>& v,long long int mid){
        int n=v.size();
        int cnt=1,temp=0;
        for(int i=0;i<n;i++){
            if(temp+v[i]<=mid){
                temp=temp+v[i];
            }
            else{
                cnt++;
                temp=v[i];
                if(temp>mid) return -1;
            }
        }
        return cnt;
    }

    int shipWithinDays(vector<int>& v, int days) {
        int n=v.size();
        long long int low=0,high=INT_MAX,ans=0;
        
        while(low<=high){
            long long int mid=low+(high-low)/2;
            long long int x = sum(v,mid);
            if(x<=days && x!=-1){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};