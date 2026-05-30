class Solution {
    int func(int i,int j,vector<vector<int>>&matrix,
             int n,int m,vector<vector<int>>&dp){

        if(dp[i][j]!=-1) return dp[i][j];

        int ans=1;

        int i1=i;
        int j1=j+1;
        if(i1>=0 && i1<n && j1>=0 && j1<m &&
           matrix[i1][j1]>matrix[i][j]){
            ans=max(ans,1+func(i1,j1,matrix,n,m,dp));
        }

        i1=i;
        j1=j-1;
        if(i1>=0 && i1<n && j1>=0 && j1<m &&
           matrix[i1][j1]>matrix[i][j]){
            ans=max(ans,1+func(i1,j1,matrix,n,m,dp));
        }

        i1=i-1;
        j1=j;
        if(i1>=0 && i1<n && j1>=0 && j1<m &&
           matrix[i1][j1]>matrix[i][j]){
            ans=max(ans,1+func(i1,j1,matrix,n,m,dp));
        }

        i1=i+1;
        j1=j;
        if(i1>=0 && i1<n && j1>=0 && j1<m &&
           matrix[i1][j1]>matrix[i][j]){
            ans=max(ans,1+func(i1,j1,matrix,n,m,dp));
        }

        return dp[i][j]=ans;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        int maxi=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi=max(maxi,func(i,j,matrix,n,m,dp));
            }
        }

        return maxi;
    }
};