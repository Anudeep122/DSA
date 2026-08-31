class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> v = nums;
        v.insert(v.end(),nums.begin(),nums.end());
        int n=v.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=v[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(v[i]);
        }
        

        int m=nums.size();
        vector<int> ans2(m,-1);
        for(int i=0;i<m;i++){
            ans2[i]=ans[i];
        }
        return ans2;

    }
};