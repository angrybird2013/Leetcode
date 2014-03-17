class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v(n), f(n);
        for(int i=0; i<n; i++) {
            v.at(i) = i+1;
            f.at(i) = i>0?f.at(i-1)*i:1;
        }
        string s = "";
        k--;
        for(int i=0; i<n; i++) {
            int t = f.at(n-1-i);
            int j = k/t;
            char c = '0' + v[j];
            v.erase(v.begin()+j);
            s.push_back(c);
            k = k%t;
        }
        return s;
    }
};