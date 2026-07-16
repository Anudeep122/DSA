class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi=prices[0];
        int ma=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            mi=min(mi,prices[i]);
            
            int cost=prices[i]-mi;
            ma=max(ma,cost);
            cout<<mi<<" "<<ma<<"\n";
        }
        return ma;
    }
};