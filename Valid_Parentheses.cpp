class Solution {
public:
    bool isValid(string s) {
        deque<char> q;
        int n = s.size();
        for(int i=0; i<n; i++) {
            char c = s[i], cc;
            switch(c) {
                case '(':
                case '{':
                case '[':
                    q.push_back(c);
                    break;
                case ')':
                    if(q.empty())
                        return false;
                    cc = q.back();
                    if(cc != '(')
                        return false;
                    else 
                        q.pop_back();
                    break;
                case '}':
                    if(q.empty())
                        return false;
                    cc = q.back();
                    if(cc != '{')
                        return false;
                    else 
                        q.pop_back();
                    break;
                case ']':
                    if(q.empty())
                        return false;
                    cc = q.back();
                    if(cc != '[')
                        return false;
                    else 
                        q.pop_back();
                    break;
                default:
                    return false;
            }
        }
        return q.empty();
    }
};