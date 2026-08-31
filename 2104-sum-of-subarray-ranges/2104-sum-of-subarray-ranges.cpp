class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        //subarrays of max-subarrays of min
        long long int mod=1e9+7;
        int n=nums.size();
        // MINIMUM
        
        stack<int> st;
        stack<int> st2;
        //pse
        vector<int> pse(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i] ){
                st.pop();
            }
            if(st.empty()) pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }
        //nse
        vector<int> nse(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && nums[st2.top()]>nums[i] ){
                st2.pop();
            }
            if(st2.empty()) nse[i]=n;
            else nse[i]=st2.top();
            st2.push(i);
        }
        //min sum
        long long int mi=0;
        for(int i=0;i<n;i++){
            int l=i-pse[i];
            int r=nse[i]-i;
            mi=(mi+(l*1LL*r*nums[i]));
        }

        // MAXIMUM
        
        stack<int> st3;
        stack<int> st4;
        //pge
        vector<int> pge(n,-1);
        for(int i=0;i<n;i++){
            while(!st3.empty() && nums[st3.top()]<=nums[i] ){
                st3.pop();
            }
            if(st3.empty()) pge[i]=-1;
            else pge[i]=st3.top();
            st3.push(i);
        }
        //nge
        vector<int> nge(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st4.empty() && nums[st4.top()]<nums[i] ){
                st4.pop();
            }
            if(st4.empty()) nge[i]=n;
            else nge[i]=st4.top();
            st4.push(i);
        }
        //min sum
        long long int ma=0;
        for(int i=0;i<n;i++){
            int x=i-pge[i];
            int y=nge[i]-i;
            ma=(ma+(x*y*1LL*nums[i]));
        }
        return ma-mi;
    }
};