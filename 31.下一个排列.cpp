/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      if (nums.empty()) return;
      int first_num = -1;
      int second_num = -1;
      for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i-1] > nums[i]) {
          continue;
        }
        first_num = i-1;
      }

      if (first_num > 0) {
        for (size_t i = first_num+1; i < nums.size(); ++i) {
            if (nums[i] > nums[first_num]) {
              second_num = i;
            }
        }
        std::swap(nums[first_num], nums[second_num]);
      } else {
        int i = 0;
        int j = nums.size()-1;
        while (i < j) {
          std::swap(nums[i++], nums[j--]);
        }
      }
    }
};

// @lc code=end

