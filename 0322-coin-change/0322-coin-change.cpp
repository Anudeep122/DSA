class Solution {
public:
    int fun(int ind,int k,vector<int>& coins,vector<vector<int>>& dp){
        if(ind==0){
            if(k%coins[ind]==0) return k/coins[ind];
            else return 1e9;
        }
        if(dp[ind][k]!=-1) return dp[ind][k];
        int not_take=fun(ind-1,k,coins,dp);
        int take=1e9;
        if(coins[ind]<=k) take=1+fun(ind,k-coins[ind],coins,dp);
        return dp[ind][k]=min(take,not_take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int ans=fun(n-1,amount,coins,dp);
        if(ans>1e8) return -1;
        else return ans;
    }
};