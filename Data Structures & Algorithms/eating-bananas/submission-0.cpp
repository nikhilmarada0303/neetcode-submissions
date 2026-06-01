class Solution {
    bool func(int k,vector<int>&piles,int h){
        int cnt=0;
        for(int i=0;i<piles.size();i++){
            int f;
            if(piles[i]%k) f=(piles[i]/k)+1;
            else f=piles[i]/k;
            cnt=cnt+f;
        }if(cnt<=h) return 1;
        return 0;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r;
        for(auto it:piles) r=max(r,it);
        while(l<=r){
            int mid=(l+r)/2;
            if(func(mid,piles,h)) r=mid-1;
            else l=mid+1;
        }return l;
    }
};
