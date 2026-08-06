class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int l=0,r=0;
        int n=s.size();
        int ans=0;
        while(l<n && r<n){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
                
            }
            ans=max(ans,r-l+1);
            r++;
        }

        return ans;
    }
};