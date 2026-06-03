class Solution {
    bool func(int ind,vector<int>&nums,int n){
        if(ind==n) return 1;

        bool take=0;
        for(int i=1;i<=nums[ind];i++){
            if(func(ind+i,nums,n)) return 1;
        }
        return 0;
    }
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size()-1;
        return func(0,nums,n);
    }
};
