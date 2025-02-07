class Solution {
public:
    vector<int> queryResults(const int &limit, const vector<vector<int>>& q) {
        const int n = q.size();
        vector<int> ans(n,-1);
        unordered_map<int,int> mp;
        unordered_map<int,int> dis;
        for(int i = 0;i < n;i++){
            if(mp.find(q[i][0]) != mp.end()){
                dis[mp[q[i][0]]]--;
                if(dis[mp[q[i][0]]] == 0) dis.erase(mp[q[i][0]]);
                mp[q[i][0]] = q[i][1];
                dis[q[i][1]]++;
            }
            else{
                mp[q[i][0]] = q[i][1];
                dis[q[i][1]]++;
            }

            ans[i] = dis.size();
        }
        return ans;
    }
};
