class Solution {
public:
    void reverseWords(string &s) {
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(s[i] == ' ' && (i == 0 || i == n-1 || s[i+1] == ' ')) {
                s.erase(i, 1);
                n--;
                i--;
            }
        }
        for(int i=0; i<n/2; i++) {
            char t = s[i];
            s[i] = s[n-1-i];
            s[n-1-i] = t;
        }
        int p = 0;
        for(int i=0; i<=n; i++) {
            if(i == n || s[i] == ' ') {
                int q = i-1;
                for(int j=p; j<=(q+p-1)/2; j++) {
                    char t = s[j];
                    s[j] = s[q+p-j];
                    s[q+p-j] = t;
                }
                p = i+1;
                if(i == n)
                    return;
            }
        }
    }
};