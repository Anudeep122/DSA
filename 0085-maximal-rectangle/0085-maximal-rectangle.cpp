class Solution {
public:

    int f(vector<int>& a) {
        int n=a.size();
        int ans=0;
        vector<int> prev(n,-1);
        vector<int> next(n,n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[st.top()]>=a[i]){
                st.pop();
            }
            if(st.empty()) next[i]=n;
            else next[i]=st.top();
            st.push(i);
        }

        stack<int> st2;
        for(int i=0;i<n;i++){
            while(!st2.empty() && a[st2.top()]>=a[i]){
                st2.pop();
            }
            if(st2.empty()) prev[i]=-1;
            else prev[i]=st2.top();
            st2.push(i);
        }

        for(int i=0;i<n;i++){
            int l=i-prev[i];
            int r=next[i]-i;
            int x=(r+l-1)*a[i];
            ans=max(ans,x);
        }
        return ans;
        
    }

    int maximalRectangle(vector<vector<char>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int ans=0;
        vector<int> v(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]=='0') v[j]=0;
                else v[j]++;
            }
            int x=f(v);
            ans=max(ans,x);
        }
        return ans;
    }
};