class Solution {
    int func(int ind1,int ind2,string word1,string word2,int n,int m,vector<vector<int>>&dp){
        if(ind2==m) return n-ind1;
        if(ind1==n) return m-ind2;

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(word1[ind1]==word2[ind2]){
            return dp[ind1][ind2]=func(ind1+1,ind2+1,word1,word2,n,m,dp);
        }
        return dp[ind1][ind2]=1+min(func(ind1+1,ind2,word1,word2,n,m,dp),min(func(ind1,ind2+1,word1,word2,n,m,dp),func(ind1+1,ind2+1,word1,word2,n,m,dp)));
    
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(0,0,word1,word2,n,m,dp);
    }
};
