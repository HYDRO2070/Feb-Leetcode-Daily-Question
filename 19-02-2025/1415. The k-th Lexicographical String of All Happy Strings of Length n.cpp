class Solution {
    void solve(int &n,string &s,int &k,string &ans,bool &flag){
        if(n == 0){
            if(--k == 0){
                 ans = s;
                 flag = true;
            }
            return;
        }
        int size = s.size();
        if((size == 0 || (s[size-1] != 'a' )) && !flag){
            s.push_back('a');
            n--;

            solve(n,s,k,ans,flag);
            n++;
            s.pop_back();
        }
        if((size == 0 || (s[size-1] != 'b' )) && !flag){
            s.push_back('b');
            n--;

            solve(n,s,k,ans,flag);
            n++;
            s.pop_back();
        }
        if((size == 0 || (s[size-1] != 'c' )) && !flag){
            s.push_back('c');
            n--;

            solve(n,s,k,ans,flag);
            n++;
            s.pop_back();
        }


    }
public:
    string getHappyString(int n, int k) {
        string ans = "";
        string s = "";
        bool flag = false;
        solve(n,s,k,ans,flag);
        return ans;
    }
};
