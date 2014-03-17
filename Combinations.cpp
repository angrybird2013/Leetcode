class Solution {
public:
    void move(vector<vector<int>> &vv, vector<int> v, int p, int max) {
        vv.push_back(v);
        if(p < 0)
            return;
        int min = v[p]+1;
        for(int i=min; i<max; i++) {
            v[p] = i;
            move(vv, v, p-1, i);
        }
    }

    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> t(k);
        for(int i=0; i<k; i++)
            t[i] = i+1;
        move(result, t, k-1, n+1);
        return result;
    }
};