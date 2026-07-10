class Solution {
public:
    int fun(int i,int j,string str1,string str2,vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(str1[i]==str2[j]) return dp[i][j]=fun(i-1,j-1,str1,str2,dp);
        return dp[i][j]=min(1+fun(i-1,j,str1,str2,dp),min(1+fun(i,j-1,str1,str2,dp),1+fun(i-1,j-1,str1,str2,dp)));
    }

    int minDistance(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return fun(n,m,str1,str2,dp);
    }
};