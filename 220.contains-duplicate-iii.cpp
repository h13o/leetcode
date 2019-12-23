/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 *
 * https://leetcode.com/problems/contains-duplicate-iii/description/
 *
 * algorithms
 * Medium (20.30%)
 * Likes:    839
 * Dislikes: 857
 * Total Accepted:    107.2K
 * Total Submissions: 527K
 * Testcase Example:  '[1,2,3,1]\n3\n0'
 *
 * Given an array of integers, find out whether there are two distinct indices
 * i and j in the array such that the absolute difference between nums[i] and
 * nums[j] is at most t and the absolute difference between i and j is at most
 * k.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1], k = 3, t = 0
 * Output: true
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,0,1,1], k = 1, t = 2
 * Output: true
 *
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,5,9,1,5,9], k = 2, t = 3
 * Output: false
 *
 *
 *
 *
 */

// @lc code=start
class Solution
{
    map<int, int> mp;

public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(nums[i]) != mp.end())
            {
                auto it = mp.find(nums[i]);
                while (0 < i - it->second && i - it->second < k)
                {
                }
                it = mp.find(nums[i]);
                while (-k < i - it->second && i - it->second < 0)
                {
                }
            }
            mp[nums[i]] = i;
        }
    }
};
// @lc code=end
