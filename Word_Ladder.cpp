class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        int ret = 0;
        if(start == end)
            return ret;
        unordered_set<string> added;
        queue<string> q;
        string mark = "#";
        q.push(start);
        added.insert(start);
        q.push(mark);
        while(q.size()>1) {
            string s = q.front();
            q.pop();
            if(s == mark) {
                ret++;
                q.push(s);
            }
            else {
                if(s == end)
                    return ret+1;
                int n = s.size();
                for(int i=0; i<n; i++) {
                    for(int j=0; j<26; j++) {
                        string t = s;
                        t[i] = 'a'+j;
                        if(dict.find(t) != dict.end() && added.find(t) == dict.end()) {
                            q.push(t);
                            added.insert(t);
                        }
                    }
                }
            }
        }
        return 0;
    }
};