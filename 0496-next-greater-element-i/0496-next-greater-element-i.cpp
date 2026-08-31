class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans(m,-1);
        stack<int> st;
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i] ){
                st.pop();
            }
            
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(nums2[i]);
        }

        vector<int> ind(10005,0);
        for(int i=0;i<m;i++){
            ind[nums2[i]] = i;
        }
        vector<int> ans2(n,-1);

        for(int i=0;i<n;i++){
            ans2[i] = ans[ind[nums1[i]]];
        }

        return ans2;
        
    }
};