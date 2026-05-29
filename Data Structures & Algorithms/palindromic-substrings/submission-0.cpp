class Solution {
public:
     int longestPalindrome(string s) {
        int maxi=0;
        int cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int l=i;
            int r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                    cnt++;
                
                l--;r++;
            }
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                    cnt++;
                l--;r++;
            }
        }return cnt;
    }

    int countSubstrings(string s) {
        return longestPalindrome(s);
    }
};
