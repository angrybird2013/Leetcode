class Solution {
public:
    int jump(int A[], int n) {
        int step[n];
        step[n-1] = 0;
        for(int i=n-2; i>=0; i--) {
            int k = A[i];
            if(i+k>=n-1)
                step[i] = 1;
            else {
                int min = n;
                for(int j=k; j>0 ; j--) {
                    if(step[i+j] == 1) {
                        min = 1;
                        break;
                    }
                    else if(step[i+j] < min)
                        min = step[i+j];
                }
                step[i] = min + 1;
            }
        }
        return step[0];
    }
};