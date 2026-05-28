class Solution {
    bool func(int ind,int k,vector<int>&nums,int n,vector<vector<int>>&dp){
        if(k==0) return 1;
        if(ind>=n) return 0;

        if(dp[ind][k]!=-1) return dp[ind][k];
        int take=0;
        if(nums[ind]<=k) take=func(ind+1,k-nums[ind],nums,n,dp);
        int not_take=func(ind+1,k,nums,n,dp);
        return dp[ind][k]=take || not_take;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return 0;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return func(0,sum/2,nums,n,dp);
    }
};
