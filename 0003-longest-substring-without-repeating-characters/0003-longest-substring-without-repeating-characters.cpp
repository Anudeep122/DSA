class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int l=0,r=0,ans=0;
        map <char,int> mp;
        while(l<n && r<n){
            if(mp[s[r]]<1){
                mp[s[r]]++;
                r++;
                ans=max(r-l,ans);
            }
            else{
                ans=max(r-l,ans);
                mp[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};