class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        vector<int> prev(3,-1);

        int ans = 0;
        for(int i=0;i<n;i++){
            prev[s[i]-'a'] = i;
            int mi = min(prev[0],min(prev[1],prev[2]));
            if(mi==-1)continue;
            else ans += mi+1;
        }
        
        return ans;
    }
};