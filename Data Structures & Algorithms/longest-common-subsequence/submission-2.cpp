class Solution {
    int func(int i,int j,string a,string b,int n,int m,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        if(a[i]==b[j]){
            take=1+func(i-1,j-1,a,b,n,m,dp);
        }
        int n_take=max(func(i-1,j,a,b,n,m,dp),func(i,j-1,a,b,n,m,dp));
        return dp[i][j]=max(take,n_take);
    }
public:
    int longestCommonSubsequence(string a, string b) {
        int n=a.size();
        int m=b.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                 int take=0;
        if(a[i-1]==b[j-1]){
            take=1+dp[i-1][j-1];
        }
        int n_take=max(dp[i-1][j],dp[i][j-1]);
        dp[i][j]=max(take,n_take);
            }
        }
        return dp[n][m];
    }
};
