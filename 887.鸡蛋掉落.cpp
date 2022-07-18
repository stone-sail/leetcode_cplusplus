/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */

// @lc code=start
class Solution {
public:
    std::unordered_map<int, std::unordered_map<int>> result_;
    int superEggDrop(int k, int n) {
        for(auto i = 0; i < n; ++i) {
            result_[1][n] = n;
            result_[0][n] = 0;
        }
    }

    int DFS(int k, int n) {
        int result = 0;
        if (k == 1) {
            result = n;
        } else {}

    }

};
// @lc code=end

