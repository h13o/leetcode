/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 *
 * https://leetcode.com/problems/binary-search/description/
 *
 * algorithms
 * Easy (49.96%)
 * Likes:    388
 * Dislikes: 36
 * Total Accepted:    87.7K
 * Total Submissions: 175.6K
 * Testcase Example:  '[-1,0,3,5,9,12]\n9'
 *
 * Given a sorted (in ascending order) integer array nums of n elements and a
 * target value, write a function to search target in nums. If target exists,
 * then return its index, otherwise return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-1,0,3,5,9,12], target = 9
 * Output: 4
 * Explanation: 9 exists in nums and its index is 4
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-1,0,3,5,9,12], target = 2
 * Output: -1
 * Explanation: 2 does not exist in nums so return -1
 *
 *
 *
 *
 * Note:
 *
 *
 * You may assume that all elements in nums are unique.
 * n will be in the range [1, 10000].
 * The value of each element in nums will be in the range [-9999, 9999].
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l{-1}, r{nums.size()}, m;
        while (r - l > 1)
        {
            m = (l + r) / 2;
            if (nums[m] == target)
                return m;
            nums[m] < target ? l = m : r = m;
        }
        return -1;
    }
};
// @lc code=end
