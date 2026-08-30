class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n=a.size();
        stack <int> st;
        int i=0;
        while(i<n){
            while(!st.empty() && i<n && (st.top()>0 && a[i]<0)){
                if(abs(st.top())==abs(a[i])){
                    st.pop();i++;
                }
                else if(abs(st.top()<abs(a[i]))) st.pop();
                else i++;
            }
            if(i<n) st.push(a[i]);
            i++;
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};