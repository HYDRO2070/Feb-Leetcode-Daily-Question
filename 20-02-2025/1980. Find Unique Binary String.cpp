class Solution {
private:
    void solve(int n,string &temp,string &ans,bool &found,unordered_map<string,bool> &m){
        if(n <= 0){
            if(m.find(temp) != m.end()) return;
            ans = temp;
            found = true;
            return;
        }

        temp.push_back('0');
        if(!found)
        solve(n-1,temp,ans,found,m);
        temp.pop_back();
        temp.push_back('1');
        if(!found)
        solve(n-1,temp,ans,found,m);
        temp.pop_back();

    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,bool> m;
        for(auto& s : nums) m[s] = true;
        int n = nums[0].size();
        string ans = "";
        string temp = "";
        bool found = false;
        solve(n,temp,ans,found,m);
        return ans;
    }
};




class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            if(nums[i][i] == '0') ans.push_back('1');
            else ans.push_back('0');
        }
        return ans;
    }
};
