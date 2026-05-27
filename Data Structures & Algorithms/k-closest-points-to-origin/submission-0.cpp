class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>v;
       priority_queue<
            pair<double, pair<int,int>>,
            vector<pair<double, pair<int,int>>>,
            greater<pair<double, pair<int,int>>>
        > pq;
        for(auto it:points){
            int a=it[0];
            int b=it[1];
            double dist=sqrt(pow(a,2)+pow(b,2));
            pq.push({dist,{a,b}});
        }
        while(k>0){
            k--;
            int a=pq.top().second.first;
            int b=pq.top().second.second;
            v.push_back({a,b});
            pq.pop();
        }return v;

    }
};
