/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (43.91%)
 * Likes:    1405
 * Dislikes: 191
 * Total Accepted:    350.6K
 * Total Submissions: 798K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 *
 * Example 1:
 *
 *
 * Input: [3,4,5,1,2]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int N{nums.size()};
        if (nums[0] <= nums[N - 1])
            return nums[0];
        int l{0}, r{N - 1}, m;
        while (r - l > 1)
        {
            m = l + (r - l) / 2;
            if (nums[m - 1] > nums[m])
                return nums[m];
            if (nums[l] < nums[m])
                l = m;
            if (nums[m] < nums[r])
                r = m;
        }
        return nums[r];
    }
};
// @lc code=end
