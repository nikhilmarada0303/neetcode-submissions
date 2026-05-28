class Solution {
    map<pair<int,string>,bool>dp;
    bool func(int ind,string check,set<string>&mp,string s,int n){
        if(ind==n){
            if(check=="") return 1;
            if(mp.find(check)!=mp.end()) return 1;
            return 0;
        }
        if(dp.find({ind,check})!=dp.end()) return dp[{ind,check}];
        bool take=0;
        check=check+s[ind];
        if(mp.find(check)!=mp.end()){
            take=func(ind+1,"",mp,s,n);
           
        }
        bool n_take=func(ind+1,check,mp,s,n);
        return dp[{ind,check}]=take || n_take;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>mp;
        for(auto it:wordDict){
            mp.insert(it);
        }
        int n=s.size();
        
        return func(0,"",mp,s,n);
    }
};
