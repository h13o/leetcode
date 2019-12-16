/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (42.23%)
 * Likes:    1151
 * Dislikes: 1641
 * Total Accepted:    290.1K
 * Total Submissions: 686.4K
 * Testcase Example:  '[1,2,3,1]'
 *
 * A peak element is an element that is greater than its neighbors.
 *
 * Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element
 * and return its index.
 *
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 *
 * You may imagine that nums[-1] = nums[n] = -∞.
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index
 * number 2.
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 1 or 5
 * Explanation: Your function can return either index number 1 where the peak
 * element is 2,
 * or index number 5 where the peak element is 6.
 *
 *
 * Note:
 *
 * Your solution should be in logarithmic complexity.
 *
 */

// @lc code=start
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int l{-1}, r{nums.size()}, m, lv, rv;
        while (r - l > 1)
        {
            m = l + (r - l) / 2;
            lv = (m - 1 == -1) ? INT_MIN : nums[m - 1];
            rv = (m + 1 == nums.size()) ? INT_MIN : nums[m + 1];
            if (lv <= nums[m] && nums[m] >= rv)
                return m;
            if (lv <= nums[m] && nums[m] <= rv)
                l = m;
            if (lv >= nums[m] && nums[m] >= rv)
                r = m;
            else
                l = m;
        }
        return m;
    }
};
// @lc code=end
