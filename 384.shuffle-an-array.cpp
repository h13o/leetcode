/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 *
 * https://leetcode.com/problems/shuffle-an-array/description/
 *
 * algorithms
 * Medium (51.35%)
 * Likes:    361
 * Dislikes: 822
 * Total Accepted:    98.8K
 * Total Submissions: 192K
 * Testcase Example:  '["Solution","shuffle","reset","shuffle"]\n[[[1,2,3]],[],[],[]]'
 *
 * Shuffle a set of numbers without duplicates.
 *
 *
 * Example:
 *
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 *
 * // Shuffle the array [1,2,3] and return its result. Any permutation of
 * [1,2,3] must equally likely to be returned.
 * solution.shuffle();
 *
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 *
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 *
 *
 */

// @lc code=start
class Solution
{
    vector<int> default_nums;
    int size;

public:
    Solution(vector<int> &nums)
    {
        default_nums = nums;
        size = nums.size();
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        nums = default_nums;
        return nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        vector<int> temp;
        while (nums.size() > 0)
        {
            temp.push_back(nums[])
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
