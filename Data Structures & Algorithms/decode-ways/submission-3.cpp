class Solution {
    int func(int ind,string s,int n,vector<int>&dp){
        if(ind==n) return 1;
        if(s[ind]=='0') return 0;

        if(dp[ind]!=-1) return dp[ind];
        int oneDigit=func(ind+1,s,n,dp);
        int twoDigit=0;
        if(ind+1<n){
            string g=s.substr(ind,2);
            int c=stoi(g);
            if(c>=10 && c<=26) twoDigit=func(ind+2,s,n,dp);
        }return dp[ind]=oneDigit+twoDigit;
    }
public:
    int numDecodings(string s) {
        int n=s.size();
        if(s[0]=='0') return 0;
        vector<int>dp(n+1,-1);
        return func(0,s,n,dp);
    }
};
