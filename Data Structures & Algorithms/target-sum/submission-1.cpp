class Solution {
    int func(int ind,int sum,int target,vector<int>&nums,int n,vector<vector<int>>&dp,
    int offset){
        if(ind==n) {
            if(sum==target) return 1;
            return 0;
        }

        if(dp[ind][sum+offset]!=-1) return dp[ind][sum+offset];
        int pos=func(ind+1,sum+nums[ind],target,nums,n,dp,offset);
        int neg=func(ind+1,sum-nums[ind],target,nums,n,dp,offset);
        return dp[ind][sum+offset]=pos+neg;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int s=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(2*s+3,-1));
        int ans=func(0,0,target,nums,n,dp,s);
        if(ans==-1) return 0;
        return ans;
    }
};
