class Solution {
public:
    int func(int ind,vector<int>&nums,int n,vector<int>&dp){
            if(ind==n) return 0;
            if(ind>n) return INT_MAX;

            if(dp[ind]!=-1) return dp[ind];
            int take=0;
            int mini=INT_MAX;
            for(int i=1;i<=nums[ind];i++){
                take=func(ind+i,nums,n,dp);
                if(take!=INT_MAX)
                mini=min(mini,take+1);

            }
            return dp[ind]=mini;
        }   
    int jump(vector<int>& nums) {
         int n=nums.size()-1;
        vector<int>dp(n+1,-1);
        return func(0,nums,n,dp);
    }
};
