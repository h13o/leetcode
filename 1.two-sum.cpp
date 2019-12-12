/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (umap.find(nums[i]) != umap.end())
                return {i, umap[nums[i]]};
            umap[target - nums[i]] = i;
        }
        return {INT_MIN, INT_MIN};
    }
};
// @lc code=end
