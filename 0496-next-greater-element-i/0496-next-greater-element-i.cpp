class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& arr) {
        int n=nums1.size();
        int m=arr.size();
        stack<int> st;
        vector<int> ans(m,-1);
        for(int i=0;i<m;i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }

        vector<int> ind(10005,0);
        for(int i=0;i<m;i++){
            ind[arr[i]] = i;
        }
        vector<int> ans2(n,-1);

        for(int i=0;i<n;i++){
            ans2[i] = ans[ind[nums1[i]]];
        }

        return ans2;
    }
};