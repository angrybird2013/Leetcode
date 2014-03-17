class Solution {
public:
    int sqrt(int x) {
        int a = x>46340?46340:x;
        unsigned long m = a*a;
        if(m <= x)
            return a;
        while(m > x) {
            a = a >> 1;
            m = a*a;
        }
        int i = a, j = a << 1;
        while(j-i>=1) {
            int p = (i+j) >> 1;
            m = p*p;
            if(m == x)
                return p;
            else if(m < x)
                i = p+1;
            else
                j = p-1;
        }
        return i*i>x?i-1:i;
    }
};