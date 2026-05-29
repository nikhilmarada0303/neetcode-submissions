class Solution {
    int func(int ind,int k,vector<int>&coins,int n,vector<vector<int>>&dp){
        if(k==0) return 1;
        if(ind<0) return 0;
        int take=0;
        if(dp[ind][k]!=-1) return dp[ind][k];
        if(k>=coins[ind]){
            take=func(ind,k-coins[ind],coins,n,dp);
        }
        int n_take=func(ind-1,k,coins,n,dp);
        return dp[ind][k]=take+n_take;
    }
public:
    int change(int amount, vector<int>& coins) {
         int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=func(n-1,amount,coins,n,dp);
        if(ans==-1) return 0;
        return ans;
    }
};
