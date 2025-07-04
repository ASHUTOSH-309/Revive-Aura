#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */


struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right; 
};


class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root== NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            
            int maxInRow=INT_MIN;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                if(node->val > maxInRow) maxInRow=node->val;
                q.pop();
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(maxInRow);
        }

        return ans;
    }
};