class Solution {
public:
    bool valid(vector<vector<int>> map, int x, int y, int n) {
        for(int i=0; i<y-1; i++) {
            if(map[i][x] == 1)
                return false;
        }
        for(int i=x-1, j=y-1; i>=0 && j>=0; i--, j--) {
            if(map[j][i] == 1)
                return false;
        }
        for(int i=x+1, j=y-1; i<n && j>=0; i++, j--) {
            if(map[j][i] == 1)
                return false;
        }
        return true;
    }
    
    vector<string> trans(vector<vector<int>> map, int n) {
        vector<string> v;
        for(int i=0; i<n; i++) {
            string s = "";
            for(int j=0; j<n; j++) {
                char c;
                if(map[i][j] == 1) 
                    c = 'Q';
                else
                    c = '.';
                s += c; 
            }
            v.push_back(s);
        }
        return v;
    }

    void solve(vector<vector<int>> map, int k, int n, vector<vector<string>> &vv) {
        if(k == n) {
            vector<string> v = trans(map, n);
            vv.push_back(v);
        }
        else {
            for(int i=0; i<n; i++) {
                if(valid(map, k, i, n)) {
                    map[k][i] = 1;
                    solve(map, k+1, n, vv);
                    map[k][i] = 0;
                }
            }
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> vv;
        vector<vector<int>> map(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            map[0][i] = 1;
            solve(map, 1, n, vv);
            map[0][i] = 0;
        }
        return vv;
    }
};