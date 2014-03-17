class Solution {
public:
    void dfs(vector<string> &v, string pre, string digits, int p) {
        if(p == digits.size()) {
            v.push_back(pre);
        }
        else {
            vector<char> t;
            switch(digits[p]-'2') {
                case 0:
                    t = {'a', 'b', 'c'};
                    break;
                case 1:
                    t = {'d', 'e', 'f'};
                    break;
                case 2:
                    t = {'g', 'h', 'i'};
                    break;
                case 3:
                    t = {'j', 'k', 'l'};
                    break;
                case 4:
                    t = {'m', 'n', 'o'};
                    break;
                case 5:
                    t = {'p', 'q', 'r', 's'};
                    break;
                case 6:
                    t = {'t', 'u', 'v'};
                    break;
                case 7:
                    t = {'w', 'x', 'y', 'z'};
                    break;
            }
            for(int i=0; i<t.size(); i++) {
                dfs(v, pre+t[i], digits, p+1);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> v;
        dfs(v, "", digits, 0);
        return v;
    }
};