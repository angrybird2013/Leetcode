class Solution {
public:
    void sub(vector<vector<int>> &vv, vector<int> v, vector<int> s, int k, bool mark) {
        if(mark)
            vv.push_back(v);
        if(k >= s.size())
            return;
        int t = s[k], end;
        for(end=k+1; end<s.size() && s[end] == t; end++);
        mark = false;
        for(int i=k; i<=end; i++) {
            sub(vv, v, s, end, mark);
            mark = true;
            v.push_back(s[i]);
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> vv;
        vector<int> v;
        sub(vv, v, S, 0, true);
        return vv;
    }
};