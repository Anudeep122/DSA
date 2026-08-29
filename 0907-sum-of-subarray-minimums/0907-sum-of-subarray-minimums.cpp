class Solution {
public:
    int sumSubarrayMins(vector<int>& v) {
        int n=v.size();

        stack<int> st;
        vector<int> prev(n+1,-1),nxt(n+1,n);
        for(int i=0;i<n;i++){
            while(!st.empty() && v[st.top()]>v[i]){
                nxt[st.top()] = i;
                st.pop();
            }
            
            st.push(i);
        }

        stack<int> st2;
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && v[st2.top()]>=v[i]){
                prev[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }

        long long ans = 0;
        long long mod = 1e9+7;
        for(int i=0;i<n;i++){
            long long x = i-prev[i];
            long long y = nxt[i]-i;
            long long z = (x*y)%mod;
            ans = (ans + (z*v[i])%mod)%mod;
        }

        return (long)ans;
    }
};