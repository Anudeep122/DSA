class Solution {
public:
    // int fun(int ind,int k,vector<int>& coins,vector<vector<int>>& dp){
    //     if(ind==0){
    //         if(k%coins[ind]==0) return k/coins[ind];
    //         else return 1e9;
    //     }
    //     if(dp[ind][k]!=-1) return dp[ind][k];
    //     int not_take=fun(ind-1,k,coins,dp);
    //     int take=1e9;
    //     if(coins[ind]<=k) take=1+fun(ind,k-coins[ind],coins,dp);
    //     return dp[ind][k]=min(take,not_take);
    // }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i]=1e9;
        }

        for(int i=1;i<n;i++){
            for(int k=1;k<=amount;k++){
                int take=1e9;
                int not_take=dp[i-1][k];
                if(coins[i]<=k) take=1+dp[i][k-coins[i]];
                dp[i][k]=min(take,not_take);
            }
        }

        int ans=dp[n-1][amount];
        if(ans>1e8) return -1;
        else return ans;
    }
};