class Solution {
    int func(int i,vector<int>&cost,vector<int>&dp,int n){
        if(i==n) return 0;
        if(i>n) return 1e9;
        if(dp[i]!=-1) return dp[i];
        int one=cost[i]+func(i+1,cost,dp,n);
        int two=cost[i]+func(i+2,cost,dp,n);
        return dp[i]=min(one,two);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(func(0,cost,dp,n),func(1,cost,dp,n));
    }
};
