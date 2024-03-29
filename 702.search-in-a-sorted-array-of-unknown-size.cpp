/*
 * @lc app=leetcode id=702 lang=cpp
 *
 * [702] Search in a Sorted Array of Unknown Size
 *
 * https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/description/
 *
 * algorithms
 * Medium (62.92%)
 * Likes:    221
 * Dislikes: 18
 * Total Accepted:    16.7K
 * Total Submissions: 26.4K
 * Testcase Example:  '[-1,0,3,5,9,12]\n9'
 *
 * Given an integer array sorted in ascending order, write a function to search
 * target in nums.  If target exists, then return its index, otherwise return
 * -1. However, the array size is unknown to you. You may only access the array
 * using an ArrayReader interface, where ArrayReader.get(k) returns the element
 * of the array at index k (0-indexed).
 *
 * You may assume all integers in the array are less than 10000, and if you
 * access the array out of bounds, ArrayReader.get will return 2147483647.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: array = [-1,0,3,5,9,12], target = 9
 * Output: 4
 * Explanation: 9 exists in nums and its index is 4
 *
 *
 * Example 2:
 *
 *
 * Input: array = [-1,0,3,5,9,12], target = 2
 * Output: -1
 * Explanation: 2 does not exist in nums so return -1
 *
 *
 *
 * Note:
 *
 *
 * You may assume that all elements in the array are unique.
 * The value of each element in the array will be in the range [-9999, 9999].
 *
 *
 */

// @lc code=start
// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution
{
public:
    int search(const ArrayReader &reader, int target)
    {
        if (reader.get(0) == INT_MAX)
            return -1;
        int ok{0}, ng{INT_MAX}, md;
        while (ng - ok > 1)
        {
            md = ok + (ng - ok) / 2;
            if (reader.get(md) == INT_MAX)
                ng = md;
            else
                ok = md;
        }
        int r{-1}, l{ok + 1};
        while (l - r > 1)
        {
            md = r + (l - r) / 2;
            if (reader.get(md) == target)
                return md;
            else if (reader.get(md) > target)
                l = md;
            else
                r = md;
        }
        return -1;
    }
};
// @lc code=end
