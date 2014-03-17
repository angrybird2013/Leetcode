class Solution {
public:
    string longest(string a, string b) {
        int i = 0, n = a.size(), m = b.size();
        n = n>m?m:n;
        for(; i<n; i++) {
            if(a[i] != b[i])
                break;
        }
        return a.substr(0, i);
    }
    
    string longest(vector<string> strs, int p, int q) {
        int n = q-p;
        if(n>2) {
            return longest(longest(strs, p, p+n/2), longest(strs, p+n/2, q));
        }
        else if(n==2) {
            return longest(strs[p], strs[p+1]);
        }
        else if(n==1) {
            return strs[p];
        }
        else {
            return "";
        }
    }

    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        if(n==0)
            return "";
        else if(n==1)
            return strs[0];
        string a = longest(strs, 0, n/2), b = longest(strs, n/2, n);
        return longest(a, b);
    }
};