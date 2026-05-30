class Solution {
    bool func(int ind1,int ind2,string s1,string s2,string s3,int n,int m,
    vector<vector<int>>&dp){
        if(ind1==n && ind2==m){
            return 1;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        bool take1=0;
        int k=ind1+ind2;

        if(s1[ind1]==s3[k]) take1=func(ind1+1,ind2,s1,s2,s3,n,m,dp);
        int take2=0;
        if(s2[ind2]==s3[k]) take2=func(ind1,ind2+1,s1,s2,s3,n,m,dp);
        return dp[ind1][ind2]=take1|take2;

    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        if(n+m!=s3.size()) return 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return func(0,0,s1,s2,s3,n,m,dp);
    }
};
