class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        map<int,int>mp;
        for(auto it:hand) mp[it]++;
        if(n%groupSize) return 0;

        while(!mp.empty()){
            int check=mp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mp.find(check)==mp.end()){
                    return 0;
                }
                mp[check]--;
                if(mp[check]==0) mp.erase(check);
                check++;
            }
        }return 1;
    }
};
