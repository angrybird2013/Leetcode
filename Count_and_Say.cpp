class Solution {
public:
    string say(string s) {
        string str = "";
        int count = 1;
        char pre = s[0], t;
        for(int i=1; i<s.size(); i++) {
            char c = s[i];
            if(pre == c) {
                count++;
            }
            else {
                t = '0' + count;
                str += t;
                str += pre;
                pre = c;
                count = 1;
            }
        }
        t = '0' + count;
        str += t;
        str += pre;
        return str;
    }

    string countAndSay(int n) {
        string s = "1";
        while(--n>0) {
            s = say(s);
        }
        return s;
    }
};