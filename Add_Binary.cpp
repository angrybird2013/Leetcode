class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        if(a.size()<b.size()) {
            s = a;
            a = b;
            b = s;
        }
        s = "";
        int p = a.size(), q = b.size(), carry = 0, i;
        for(i=0; i<q; i++) {
            int m = a[p-1-i]-'0', n = b[q-1-i]-'0';
            char c = (m+n+carry)%2+'0';
            carry = (m+n+carry)/2;
            s = c + s;
        }
        for(i=q; i<p; i++) {
            int k = a[p-1-i]-'0';
            char c = (k+carry)%2+'0';
            carry = (k+carry)/2;
            s = c + s;
        }
        if(carry>0) 
            s = '1' + s;
        return s;
    }
};