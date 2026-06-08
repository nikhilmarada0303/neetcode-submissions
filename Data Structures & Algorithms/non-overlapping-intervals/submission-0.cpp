class Solution1 {
public:
    static bool comp(vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
    }
    vector<vector<int>>intervals;
    Solution1(vector<vector<int>>intervals){
        this->intervals=intervals;
    }
    int eraseOverlapIntervals1(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int n=intervals.size();
        int cnt=1;
        int last=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=last){
                cnt++;
                last=intervals[i][1];
            }
        }return n-cnt;
    }
};


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        Solution1* solution1=new Solution1(intervals);
        return solution1->eraseOverlapIntervals1(intervals);
    }
};
