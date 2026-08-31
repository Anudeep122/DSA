class Solution {
public:
    int sumSubarrayMins(vector<int>& v) {
        int n=v.size();
        int mod=1e9+7;
        //next minimum
        stack<int> st;
        vector<int> nm(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && v[st.top()]>v[i] ){
                st.pop();
            }
            if(st.empty()) nm[i]=n;
            else nm[i]=st.top();
            st.push(i);
        }
        
        //prev minimum
        stack<int> st2;
        vector<int> pm(n,-1);
        for(int i=0;i<n;i++){
            while(!st2.empty() && v[st2.top()]>=v[i] ){
                st2.pop();
            }
            if(st2.empty()) pm[i]=-1;
            else pm[i]=st2.top();
            st2.push(i);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            int l=i-pm[i];
            int r=nm[i]-i;
            ans=(ans+ (l*r*1LL*v[i])%mod)%mod ;
        }
        return ans;
        
    }
};