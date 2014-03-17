/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        deque<TreeNode *> q;
        vector<vector<int>> vv;
        bool ltr = true;
        if(root != NULL)
            q.push_back(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> v(n);
            TreeNode *t;
            deque<TreeNode *> p;
            for(int i=0; i<n; i++) {
                t = q[i];
                v[i] = t->val;
                if(ltr) {
                    if(t->left != NULL)
                        p.push_front(t->left);
                    if(t->right != NULL)
                        p.push_front(t->right);
                }
                else {
                    if(t->right != NULL)
                        p.push_front(t->right);
                    if(t->left != NULL)
                        p.push_front(t->left);
                }
            }
            vv.push_back(v);
            q.clear();
            q = p;
            ltr = !ltr;
        }
        return vv;
    }
};