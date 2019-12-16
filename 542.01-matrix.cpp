/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (37.67%)
 * Likes:    928
 * Dislikes: 92
 * Total Accepted:    61.4K
 * Total Submissions: 162.8K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
 * each cell.
 *
 * The distance between two adjacent cells is 1.
 *
 *
 *
 * Example 1:
 *
 *
 * Input:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[0,0,0]]
 *
 * Output:
 * [[0,0,0],
 * [0,1,0],
 * [0,0,0]]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[1,1,1]]
 *
 * Output:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[1,2,1]]
 *
 *
 *
 *
 * Note:
 *
 *
 * The number of elements of the given matrix will not exceed 10,000.
 * There are at least one 0 in the given matrix.
 * The cells are adjacent in only four directions: up, down, left and right.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        int mv[5] = {0, 1, 0, -1, 0}, M(matrix.size()), N(matrix[0].size());
        queue<pair<int, int>> que;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (matrix[i][j])
                    que.push(make_pair(i, j));
            }
        }
        while (!que.empty())
        {
            bool check{true};
            int x{que.front().first},
                y{que.front().second};
            que.pop();
            for (int i = 0; i < 4; i++)
            {
                if (0 <= x + mv[i] && x + mv[i] < M && 0 <= y + mv[i + 1] && y + mv[i + 1] < N &&
                    matrix[x][y] > matrix[x + mv[i]][y + mv[i + 1]])
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                matrix[x][y]++;
                que.push(make_pair(x, y));
            }
        }
        return matrix;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
//     {
//         int mx[4] = {1, 0, -1, 0};
//         int my[4] = {0, 1, 0, -1};
//         size_t M{matrix.size()}, N{matrix[0].size()};
//         queue<pair<int, int>> que1, que2;
//         for (auto i = 0; i < M; i++)
//         {
//             for (auto j = 0; j < N; j++)
//             {
//                 if (matrix[i][j])
//                     que2.push(make_pair(i, j));
//             }
//         }
//         while (!que2.empty())
//         {
//             que1 = que2;
//             queue<pair<int, int>> que_empty;
//             swap(que2, que_empty);
//             while (!que1.empty())
//             {
//                 int x = que1.front().first;
//                 int y = que1.front().second;
//                 que1.pop();
//                 bool check{true};
//                 for (int i = 0; i < 4; i++)
//                 {
//                     if (0 <= x + mx[i] && x + mx[i] < M && 0 <= y + my[i] && y + my[i] < N)
//                     {
//                         if (matrix[x + mx[i]][y + my[i]] == matrix[x][y] - 1)
//                             check = false;
//                     }
//                 }
//                 if (check)
//                 {
//                     matrix[x][y]++;
//                     que2.push(make_pair(x, y));
//                 }
//             }
//         }
//         return matrix;
//     }
// };
