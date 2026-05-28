class Solution {
    int func(int ind,int k,vector<int>&coins,int n,vector<vector<int>>&dp){
        if(k==0) return 0;
        if(ind<0) return 1e9;
        int take=1e9;
        if(dp[ind][k]!=-1) return dp[ind][k];
        if(k>=coins[ind]){
            take=1+func(ind,k-coins[ind],coins,n,dp);
        }
        int n_take=func(ind-1,k,coins,n,dp);
        return dp[ind][k]=min(take,n_take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=func(n-1,amount,coins,n,dp);
        if(ans==1e9) return -1;
        return ans;
    }
};
