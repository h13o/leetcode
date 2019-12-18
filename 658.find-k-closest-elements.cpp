/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 *
 * https://leetcode.com/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (39.26%)
 * Likes:    880
 * Dislikes: 182
 * Total Accepted:    72.9K
 * Total Submissions: 185.6K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 *
 * Given a sorted array, two integers k and x, find the k closest elements to x
 * in the array.  The result should also be sorted in ascending order.
 * If there is a tie,  the smaller elements are always preferred.
 *
 *
 * Example 1:
 *
 * Input: [1,2,3,4,5], k=4, x=3
 * Output: [1,2,3,4]
 *
 *
 *
 *
 * Example 2:
 *
 * Input: [1,2,3,4,5], k=4, x=-1
 * Output: [1,2,3,4]
 *
 *
 *
 * Note:
 *
 * The value k is positive and will always be smaller than the length of the
 * sorted array.
 * ⁠Length of the given array is positive and will not exceed 10^4
 * ⁠Absolute value of elements in the array and x will not exceed 10^4
 *
 *
 *
 *
 *
 *
 * UPDATE (2017/9/19):
 * The arr parameter had been changed to an array of integers (instead of a
 * list of integers). Please reload the code definition to get the latest
 * changes.
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int sm{-1}, bg{arr.size()}, m;
        while (bg - sm > 1)
        {
            m = sm + (bg - sm) / 2;
            if (arr[m] < x)
                sm = m;
            if (arr[m] > x)
                bg = m;
            if (arr[m] == x)
            {
                sm = m;
                bg = m + 1;
            }
        }
        for (int i = 0; i < k; i++)
        {
            if (sm == -1)
                bg++;
            else if (bg == arr.size() || x - arr[sm] <= arr[bg] - x)
                sm--;
            else
                bg++;
        }
        vector<int> ans(k);
        for (int i = 0; i < k; i++)
        {
            ans[i] = arr[++sm];
        }
        return ans;
    }
};
// @lc code=end
