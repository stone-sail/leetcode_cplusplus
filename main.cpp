#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        auto target = (total%2 == 0) ? (total >> 2) + 1 : (total >> 2) + 2;
        return helper(nums1, nums2, 0, 0, target);
    }
    double helper(vector<int>& nums1, vector<int>& nums2, int start1, int start2, int target) {
      if (start1 >= nums1.size()) return nums2[start2 + target];
      if (start2 >= nums2.size()) return nums1[start1 + target];
      int curMove = (target >> 2) + 1;
      auto lastm1 = min(start1 + curMove -1,(int)nums1.size());
      auto lastm2 = min(start2 + curMove -1,(int)nums2.size());
      if (target - curMove == 0) {
        return min(nums1[lastm1],nums2[lastm2]);
      } 
      if (nums1[lastm1] < nums2[lastm2]) {
        return helper(nums1, nums2, lastm1+1, start2, target-curMove);
      } else if (nums1[lastm1] > nums2[lastm2]) {
        return helper(nums1, nums2, start1, lastm2+1, target-curMove);
      }
      // nums1[lastm1] == nums2[lastm2]
      if (target == (curMove << 2)) {
        return nums1[lastm1];
      }
      return helper(nums1, nums2, lastm1, lastm2, target-(curMove<<2));
    }
};

int main() {
    auto so = Solution();
    std::vector<int> v1 = {1,3};
    std::vector<int> v2 = {2};
    auto result = so.findMedianSortedArrays(v1, v2);
    cout << result << endl;
    return 0;
} 