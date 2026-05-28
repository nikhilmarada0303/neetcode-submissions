class Solution {
    int func(int ind,int prev,vector<int>&nums,vector<vector<int>>&dp,int n){
        if(ind==n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int take=0;
        if(prev==-1 || prev!=ind-1)
        take=nums[ind]+func(ind+1,ind,nums,dp,n);
        int n_take=func(ind+1,prev,nums,dp,n);
        return dp[ind][prev+1]=max(take,n_take);
    }
public:
    int rob(vector<int>& nums) {
     int n=nums.size();
     vector<vector<int>>dp(n,vector<int>(n+1,-1));
     return func(0,-1,nums,dp,n);   
    }
};
