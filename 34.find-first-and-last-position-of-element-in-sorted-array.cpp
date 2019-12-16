/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (34.66%)
 * Likes:    2291
 * Dislikes: 110
 * Total Accepted:    389K
 * Total Submissions: 1.1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * Example 1:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 *
 * Example 2:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return {-1, -1};
        int sl{-1}, el{-1}, sr{nums.size()}, er{nums.size()}, sm, em;
        while (sr - sl > 1)
        {
            sm = sl + (sr - sl) / 2;
            if (nums[sm] < target)
                sl = sm;
            if (nums[sm] >= target)
                sr = sm;
        }
        while (er - el > 1)
        {
            em = el + (er - el) / 2;
            if (nums[em] <= target)
                el = em;
            if (nums[em] > target)
                er = em;
        }
        return {0 <= sr && sr < nums.size() && nums[sr] == target ? sr : -1, 0 <= el && el < nums.size() && nums[el] == target ? el : -1};
    }
};
// @lc code=end
