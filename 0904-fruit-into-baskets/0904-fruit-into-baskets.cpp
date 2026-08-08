class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int l=0,r=0;
        int ans=0;
        map<int,int> mp;
        while(l<n && r<n){
            mp[fruits[r]]++;
            if(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0)
                    mp.erase(fruits[l]);
                l++;
            }
            if(mp.size()<=2) ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};