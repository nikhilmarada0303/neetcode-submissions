class Solution {
public:
    string longestPalindrome(string s) {
        int maxi=0;
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
            int l=i;
            int r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(maxi<r-l+1){
                    maxi=r-l+1;
                    ans=s.substr(l,r-l+1);
                }l--;r++;
            }
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(maxi<r-l+1){
                    maxi=r-l+1;
                    ans=s.substr(l,r-l+1);
                }l--;r++;
            }
        }return ans;
    }
};
