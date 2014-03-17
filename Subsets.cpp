class Solution {
public:
    void sub(vector<vector<int>> &vv, vector<int> v, vector<int> s, int k) {
        vv.push_back(v);
        if(k >= s.size())
            return;
        for(int i=k; i<s.size(); i++){
            v.push_back(s[i]);
            sub(vv, v, s, i+1);
            v.pop_back();
        }
    }

    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> vv;
        vector<int> v;
        sort(S.begin(), S.end());
        sub(vv, v, S, 0);
        return vv;
    }
};