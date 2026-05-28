class Solution {
    int func(int i,int n,vector<int>&dp){
        if(i==n) return 1;
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];
        int one=func(i+1,n,dp);
        int two=func(i+2,n,dp);
        return dp[i]=one+two;

    }
public:
    int climbStairs(int n) {
        vector<int>dp(n,-1);
       return func(0,n,dp); 
    }
};
