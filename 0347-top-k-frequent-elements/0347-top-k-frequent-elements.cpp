class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int> ans2;
        vector<pair<int,int>> ans(mp.begin(),mp.end());
        sort(ans.begin(), ans.end(), [](const auto& a, const auto& b) {
            return a.second > b.second; 
        });
        for(int i=0;i<k;i++){
            ans2.push_back(ans[i].first);
        }

        return ans2;
    }
};