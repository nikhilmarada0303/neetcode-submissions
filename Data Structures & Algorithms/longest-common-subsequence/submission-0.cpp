class Solution {
    int func(int i,int j,string a,string b,int n,int m,vector<vector<int>>&dp){
        if(i==n || j==m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        if(a[i]==b[j]){
            take=1+func(i+1,j+1,a,b,n,m,dp);
        }
        int n_take=max(func(i+1,j,a,b,n,m,dp),func(i,j+1,a,b,n,m,dp));
        return dp[i][j]=max(take,n_take);
    }
public:
    int longestCommonSubsequence(string a, string b) {
        int n=a.size();
        int m=b.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(0,0,a,b,n,m,dp);
    }
};
