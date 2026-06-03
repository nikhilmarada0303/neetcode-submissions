class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        for(int i=0;i<n;i++){
            int gasi=0;
            bool boo=0;
            for(int j=0;j<n;j++){
                int ind=(i+j)%n;
                gasi=gasi+gas[ind];
                
                gasi=gasi-cost[(i+j)%n];
                if(gasi<0) {boo=1;break;}
                
            }
            if(!boo) return i;
        }return -1;
    }
};
