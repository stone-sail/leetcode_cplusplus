/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-07-14 00:49:25
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-07-16 22:08:16
 * @FilePath: /blog/Users/mac/code/leetcode_cplusplus/304.二维区域和检索-矩阵不可变.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
      if (matrix.empty()) {
        return;
      }
      int rows = matrix.size();
      int cols = matrix[0].size();

      nums_ = vector<vector<int>>(rows+1, vector<int>(cols+1, 0));

      for (size_t i = 1; i <= rows + 1; ++i) {
        for (size_t j = 1; j <= cols + 1; ++j) {
          nums[i][j] = nums[i-1][j] + nums[i][j-1] - nums[i-1][j-1] + matrix[i-1][j-1];
        }
      }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
      return nums_[row2+1][col2+1] - nums_[row2+1][col1] - nums_[row1][col2+1] + nums_[row1][col1];
    }

    vector<vector<int>> nums_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

