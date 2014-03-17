class Solution {
public:
    vector<int> order(vector<vector<int> > a, int p1, int p2, int q1, int q2, vector<int> v, int k, int n) {
        if(k >= n)
            return v;
        else if(p1 >= q1 || p2 >= q2)
            return v;
        else if(p1+1 == q1) {
            for(int i=p2; i<q2; i++) 
                v[k++] = a[p1][i];
            return v;
        }
        else if(p2+1 == q2) {
            for(int i=p1; i<q1; i++)
                v[k++] = a[i][p2];
            return v;
        }
        for(int i=p2; i<q2-1; i++)
            v[k++] = a[p1][i];
        for(int i=p1; i<q1-1; i++)
            v[k++] = a[i][q2-1];
        for(int i=q2-1; i>p2; i--)
            v[k++] = a[q1-1][i];
        for(int i=q1-1; i>p1; i--)
            v[k++] = a[i][p2];
        return order(a, p1+1, p2+1, q1-1, q2-1, v, k, n);
    }

    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int m = matrix.size(), n;
        if(m == 0)
            n = 0;
        else
            n = matrix[0].size();
        vector<int> v(m*n);
        return order(matrix, 0, 0, m, n, v, 0, m*n);
    }
};