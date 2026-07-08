class Solution {
public:
    // int fun(int i,int j,string s,string str,vector<vector<int>> &dp){
    //     if(i<0||j<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==str[j]) return dp[i][j]=1+fun(i-1,j-1,s,str,dp);
    //     return dp[i][j]=max(fun(i-1,j,s,str,dp),fun(i,j-1,s,str,dp));
    // }

    int longestPalindromeSubseq(string s) {
        string str=s;
        reverse(str.begin(),str.end());
        int n=str.length();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        for(int i=0;i<=n;i++) dp[0][i]=0;
        for(int i=0;i<=n;i++) dp[i][0]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==str[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};