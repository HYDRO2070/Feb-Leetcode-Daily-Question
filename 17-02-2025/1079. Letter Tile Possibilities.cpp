class Solution {
    private:
    bool check(vector<int> &letter){
        for(auto& n : letter) if(n != 0) return false;
        return true;
    }
    void solve(vector<int> &letter,string &temp,unordered_set<string> &s){
        if(check(letter)){
            cout<<temp<<endl;
            if(temp.size() > 0)
            s.insert(temp);
        }
        for(int i = 0;i < 26;i++){
            if(letter[i] != 0){
                temp.push_back('A' + i);
                s.insert(temp);
                letter[i]--;
                solve(letter,temp,s);
                letter[i]++;
                temp.pop_back();
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        vector<int> letter(26,0);
        unordered_set<string> s;
        string temp = "";
        for(char c : tiles) letter[c - 'A']++;
        solve(letter,temp,s);
        return s.size();
    }
};




class Solution {
private:
    void solve(vector<int> &letter, int &count) {
        for(int i = 0; i < 26; i++) {
            if(letter[i] > 0) {
                count++; 
                letter[i]--;
                solve(letter, count);
                letter[i]++;
            }
        }
    }

public:
    int numTilePossibilities(string tiles) {
        vector<int> letter(26, 0);
        for(char c : tiles) letter[c - 'A']++;
        
        int count = 0;
        solve(letter, count);
        return count;
    }
};
