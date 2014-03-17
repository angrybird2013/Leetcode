class Solution {
public:
    int removeDuplicates(int A[], int n) {
        for(int i=0; i<n; ) {
            int start = i, end = i+1;
            while(end < n && A[start] == A[end])
                end++;
            if(end == n)
                return (start+2)>end?n:start+2;
            if(end-start>2) {
                int j;
                for(j=start+2; end<n; j++, end++)
                    A[j] = A[end];
                n = j;
                i = start+2;
            }
            else
                i = end;
        }
        return n;
    }
};