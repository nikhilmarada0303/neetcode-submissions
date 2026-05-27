class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int> mp;

        for(auto it : tasks){
            mp[it]++;
        }

        int ans = 0;

        vector<int> last(26, -(n + 1));

        while(mp.size() > 0){

            bool found = false;

            char choose = '#';

            int maxi = 0;

            for(auto it : mp){

                char ch = it.first;

                if(ans - last[ch - 'A'] > n){

                    if(it.second > maxi){

                        maxi = it.second;

                        choose = ch;

                        found = true;
                    }
                }
            }

            if(found){

                last[choose - 'A'] = ans;

                mp[choose]--;

                if(mp[choose] == 0){
                    mp.erase(choose);
                }
            }

            ans++;
        }

        return ans;
    }
};