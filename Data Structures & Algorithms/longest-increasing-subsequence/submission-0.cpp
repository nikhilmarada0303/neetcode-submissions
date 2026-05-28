class Solution {
    int func(int ind,int prev,vector<int>&nums,int n
    ,vector<vector<int>>&dp){
        if(ind>=n) return 0;

        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int take=0;
        if(prev==-1 || nums[ind]>nums[prev]){
            take=1+func(ind+1,ind,nums,n,dp);
        }int n_take=func(ind+1,prev,nums,n,dp);
        return dp[ind][prev+1]=max(take,n_take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return func(0,-1,nums,n,dp);
    }
};
