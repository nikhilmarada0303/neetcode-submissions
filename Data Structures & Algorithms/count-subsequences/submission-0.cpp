class Solution {
    int func(int ind1,int ind2,string s,string t ,int n,int m,vector<vector<int>>&dp){
        if(ind2==m) return 1;
        if(ind1==n || ind2==m) return 0;

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        if(s[ind1]==t[ind2]){
            return dp[ind1][ind2]=func(ind1+1,ind2+1,s,t,n,m,dp)+func(ind1+1,ind2,s,t,n,m,dp);
        }
        return dp[ind1][ind2]=func(ind1+1,ind2,s,t,n,m,dp);
        

    }
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(0,0,s,t,n,m,dp);
    }
};
