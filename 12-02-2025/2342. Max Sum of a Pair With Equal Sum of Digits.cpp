class Solution {
    private:
    int solve(int num){
        int sum = 0;
        while(num){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> m;
        int ans = -1;
        for(int i = 0;i < n;i++){
            int temp = solve(nums[i]);
            m[temp].push_back(nums[i]);            
        }

        for(auto& num : m){
            int s = num.second.size();
            if(s > 1){
                for(int i = 0;i < s;i++){
                    for(int j = i+1;j < s;j++){
                        ans = max(ans,num.second[i] + num.second[j]);
                    }
                }
            }
        }

        return ans;
    }
};





class Solution {
    private:
    int solve(int num){
        int sum = 0;
        while(num){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        const int n = nums.size();
        unordered_map<int,pair<int,int>> m;
        int ans = -1;
        for(int i = 0;i < n;i++){
            int temp = solve(nums[i]);
            if(m[temp].first < nums[i]){
                int t = m[temp].first;
                m[temp].first = nums[i];
                if(m[temp].second < t) m[temp].second = t;
            }            
            else if(m[temp].second < nums[i]){
                int t = m[temp].second;
                m[temp].second = nums[i];
                if(m[temp].first < t) m[temp].first = t;
            }            
        }

        for(auto& num : m){
            if(num.second.first > 0 && num.second.second > 0)
            ans = max(ans,num.second.first + num.second.second);
        }

        return ans;
    }
};



class Solution {
private:
    int numsum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        int ans = -1;

        for (int& num : nums) {
            int sum = numsum(num);
            auto& v = m[sum];

            if (v.size() < 2) v.push_back(num);
            else if (num > v[0]) {
                int temp = v[0];
                v[0] = num;
                if(temp > v[1]) v[1] = temp;
            } 
            else if (num > v[1]) {
                int temp = v[1];
                v[1] = num;
                if(temp > v[0]) v[0] = temp;
            }

            if (v.size() == 2) 
                ans = max(ans, v[0] + v[1]);
        }

        return ans;
    }
};
