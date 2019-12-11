/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (43.88%)
 * Likes:    3621
 * Dislikes: 133
 * Total Accepted:    489.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 *
 * Example 1:
 *
 *
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 *
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 *
 * Output: 3
 *
 */

// @lc code=start
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int mx[4]{1, 0, -1, 0}, my[4]{0, 1, 0, -1};
        int M{grid.size()};
        if (!M)
            return 0;
        int N{grid[0].size()}, count{};
        stack<pair<int, int>> sk;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == '0')
                    continue;
                count++;
                sk.push(make_pair(i, j));
                while (!sk.empty())
                {
                    int tx = sk.top().first;
                    int ty = sk.top().second;
                    sk.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = tx + mx[k];
                        int ny = ty + my[k];
                        if (nx >= 0 && nx < M && ny >= 0 && ny < N && '1' == grid[nx][ny])
                        {
                            grid[nx][ny] = '0';
                            sk.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
        return count;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int numIslands(vector<vector<char>> &grid)
//     {
//         int mx[4]{1, 0, -1, 0}, my[4]{0, 1, 0, -1};
//         if (grid.size() == 0)
//             return 0;
//         int m{grid.size()};
//         int n{grid[0].size()}, count{};
//         queue<pair<int, int>> q;
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (grid[i][j] == '1')
//                 {
//                     count++;
//                     grid[i][j] = '0';
//                     q.push(make_pair(i, j));
//                     while (!q.empty())
//                     {
//                         auto l = q.front();
//                         q.pop();
//                         for (int k = 0; k < 4; k++)
//                         {
//                             int nx{l.first + mx[k]}, ny{l.second + my[k]};
//                             if (0 <= nx && nx < m && 0 <= ny && ny < n && grid[nx][ny] == '1')
//                             {
//                                 grid[nx][ny] = '0';
//                                 q.push(make_pair(nx, ny));
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return count;
//     }
// };
