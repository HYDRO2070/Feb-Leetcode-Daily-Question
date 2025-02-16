class Solution {
private:
    unordered_map<string, bool> memo;

    bool solve(const string &s, int val, int index = 0, int sum = 0) {
        if (index == s.length()) return sum == val;
        
        string key = to_string(index) + "-" + to_string(sum);
        if (memo.find(key) != memo.end()) return memo[key];

        int num = 0;
        for (int i = index; i < s.length(); i++) {
            num = num * 10 + (s[i] - '0');
            if (num > val) break;
            
            if (solve(s, val, i + 1, sum + num)) return memo[key] = true;
        }

        return memo[key] = false;
    }

public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int temp = i * i;
            string str = to_string(temp);
            memo.clear();
            
            if (solve(str, i)) ans += temp;
        }
        return ans;
    }
};
