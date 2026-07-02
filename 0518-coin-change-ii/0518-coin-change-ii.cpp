class Solution {
public:
    int fun(int ind,int k,vector<int>& coins,vector<vector<int>>& dp){
        if(k==0) return 1;
        if(ind==0){
            if(k%coins[ind]==0) return 1;
            else return 0;
        }
        if(dp[ind][k]!=-1) return dp[ind][k];
        int pick=0;
        int not_pick=fun(ind-1,k,coins,dp);
        if(coins[ind]<=k) pick=fun(ind,k-coins[ind],coins,dp);
        return dp[ind][k]=pick+not_pick;

    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return fun(n-1,amount,coins,dp);
    }
};