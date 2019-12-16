/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.42%)
 * Likes:    3364
 * Dislikes: 382
 * Total Accepted:    531.2K
 * Total Submissions: 1.6M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 *
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * Example 1:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 *
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int N{nums.size()}, l{0}, r{N - 1}, m, st;
        if (!N)
            return -1;
        if (nums[0] < nums[N - 1])
            st = 0;
        else
        {
            while (r - l > 1)
            {
                m = l + (r - l) / 2;
                if (nums[m - 1] > nums[m])
                {
                    r = m;
                    break;
                }
                if (nums[l] < nums[m])
                    l = m;
                if (nums[m] < nums[r])
                    r = m;
            }
            st = r;
        }
        l = -1, r = N;
        int mm;
        while (r - l > 1)
        {
            mm = l + (r - l) / 2;
            m = (mm + st) % N;
            if (nums[m] == target)
                return m;
            if (nums[m] < target)
                l = mm;
            if (nums[m] > target)
                r = mm;
        }
        return -1;
    }
};
// @lc code=end
