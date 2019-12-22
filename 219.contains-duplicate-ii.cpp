/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (36.39%)
 * Likes:    632
 * Dislikes: 786
 * Total Accepted:    230.8K
 * Total Submissions: 633.4K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * absolute difference between i and j is at most k.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 *
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 *
 *
 *
 *
 *
 */

// @lc code=start
class Solution
{
    unordered_map<int, int> mp;

public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(nums[i]) != mp.end())
            {
                if (i - mp[nums[i]] <= k)
                    return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end
