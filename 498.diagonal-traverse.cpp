/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 *
 * https://leetcode.com/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (46.38%)
 * Likes:    476
 * Dislikes: 270
 * Total Accepted:    58.2K
 * Total Submissions: 125.4K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of M x N elements (M rows, N columns), return all elements of
 * the matrix in diagonal order as shown in the below image.
 *
 *
 *
 * Example:
 *
 *
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 *
 * Output:  [1,2,4,7,5,3,6,8,9]
 *
 * Explanation:
 *
 *
 *
 *
 *
 * Note:
 *
 * The total number of elements of the given matrix will not exceed 10,000.
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
    {
        int M = matrix.size();
        vector<int> ans;
        if (!M)
            return ans;
        int N = matrix[0].size();
        ans.push_back(matrix[0][0]);
        int r{0}, c{1};
        for (int K = 1; K < M + N - 1; K++)
        {
            if (c == 0)
            {
                while (r >= 0)
                {
                    if (r < M && c < N)
                        ans.push_back(matrix[r][c]);
                    r--;
                    c++;
                }
                r = 0;
            }
            else
            {
                while (c >= 0)
                {
                    if (r < M && c < N)
                        ans.push_back(matrix[r][c]);
                    r++;
                    c--;
                }
                c = 0;
            }
        }
        return ans;
    }
};
// @lc code=end
