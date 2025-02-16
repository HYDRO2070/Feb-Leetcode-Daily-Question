class Solution {
private:
    void solve(vector<int> &arr, int n, vector<int> &ans) {
        if (n == 1) {
            for(auto& num : arr) cout << num << " ";
            cout << endl;
            if (arr > ans) ans = arr;
            return;
        }

        int i = 0;

        while(i < arr.size()){
            if(arr[i] != 1 || i+n >= arr.size() || (arr[i] == 1 && arr[i+n] != 1)){
                i++;
                continue;
            }
                cout<<ans[i]<<" "<<i<<" "<<arr[i]<<endl;
                arr[i] = arr[i+n] = n;
                if(ans[i] <= arr[i])
                solve(arr, n-1, ans);
                else cout<<ans[i]<<" "<<i<<" "<<arr[i]<<endl;
                arr[i] = arr[i+n] = 1;
            i++;
        }
    }

public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, -1);
        vector<int> arr(2 * n - 1, 1);
        arr[0] = arr[n] = n;
        solve(arr, n-1, ans);
        return ans;
    }
};





class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2 * n - 1, 0);
        unordered_set<int> used;
        backtrack(result, used, 0, n);
        return result;
    }

private:
    bool backtrack(vector<int>& result, unordered_set<int>& used, int index, int n) {
        if (index == result.size()) {
            return true;
        }

        if (result[index] != 0) {
            return backtrack(result, used, index + 1, n);
        }

        for (int num = n; num >= 1; --num) {
            if (used.find(num) != used.end()) continue;
            if (num == 1) {
                result[index] = 1;
                used.insert(1);
                if (backtrack(result, used, index + 1, n)) {
                    return true;
                }
                used.erase(1);
                result[index] = 0;
            } else {
                if (index + num < result.size() && result[index + num] == 0) {
                    result[index] = num;
                    result[index + num] = num;
                    used.insert(num);
                    if (backtrack(result, used, index + 1, n)) {
                        return true;
                    }
                    used.erase(num);
                    result[index] = 0;
                    result[index + num] = 0;
                }
            }
        }

        return false;
    }
};
