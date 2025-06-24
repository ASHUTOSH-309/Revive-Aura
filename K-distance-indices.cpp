#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {

        vector<int> ans;

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // check in left k steps

            bool flag=false;
            for (int j = i; j >= i - k && j >= 0; j--) {
                if (nums[j] == key) {
                    ans.push_back(i);
                    flag=true;
                    break;
                }
            }
            for (int j = i + 1; j <= i + k && j < n; j++) {
                if (nums[j] == key) {
                    if(flag) break;
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};