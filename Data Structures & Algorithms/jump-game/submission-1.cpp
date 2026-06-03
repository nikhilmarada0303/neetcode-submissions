class Solution {
    bool func(int ind,vector<int>&nums,int n,vector<int>&dp){
        if(ind==n) return 1;

        if(dp[ind]!=-1) return dp[ind];
        bool take=0;
        for(int i=1;i<=nums[ind];i++){
            if(func(ind+i,nums,n,dp)) return dp[ind]=1;
        }
        return dp[ind]=0;
    }
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size()-1;
        vector<int>dp(n+1,-1);
        return func(0,nums,n,dp);
    }
};
