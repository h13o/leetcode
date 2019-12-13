/*
 * @lc app=leetcode id=286 lang=cpp
 *
 * [286] Walls and Gates
 *
 * https://leetcode.com/problems/walls-and-gates/description/
 *
 * algorithms
 * Medium (51.42%)
 * Likes:    805
 * Dislikes: 13
 * Total Accepted:    92.8K
 * Total Submissions: 180.4K
 * Testcase Example:  '[[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]'
 *
 * You are given a m x n 2D grid initialized with these three possible
 * values.
 *
 *
 * -1 - A wall or an obstacle.
 * 0 - A gate.
 * INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647
 * to represent INF as you may assume that the distance to a gate is less than
 * 2147483647.
 *
 *
 * Fill each empty room with the distance to its nearest gate. If it is
 * impossible to reach a gate, it should be filled with INF.
 *
 * Example: 
 *
 * Given the 2D grid:
 *
 *
 * INF  -1  0  INF
 * INF INF INF  -1
 * INF  -1 INF  -1
 * ⁠ 0  -1 INF INF
 *
 *
 * After running your function, the 2D grid should be:
 *
 *
 * ⁠ 3  -1   0   1
 * ⁠ 2   2   1  -1
 * ⁠ 1  -1   2  -1
 * ⁠ 0  -1   3   4
 *
 *
 */

// @lc code=start
// Dec 13th, 2019
class Solution
{
    int mx[4] = {1, 0, -1, 0};
    int my[4] = {0, 1, 0, -1};

public:
    void wallsAndGates(vector<vector<int>> &rooms)
    {
        int M = rooms.size();
        if (!M)
            return;
        int N = rooms[0].size();
        queue<int> qx, qy;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (rooms[i][j] == 0)
                {
                    qx.push(i);
                    qy.push(j);
                }
            }
        }
        while (!qx.empty())
        {
            int x{qx.front()}, y{qy.front()};
            qx.pop();
            qy.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx{x + mx[i]}, ny{y + my[i]};
                if (nx < 0 || M <= nx || ny < 0 || N <= ny || rooms[nx][ny] != INT_MAX)
                    continue;
                rooms[nx][ny] = rooms[x][y] + 1;
                qx.push(nx);
                qy.push(ny);
            }
        }
    }
};
// @lc code=end

// void wallsAndGates(vector<vector<int>> &rooms)
// {
//     vector<int> mx{1, 0, -1, 0};
//     vector<int> my{0, 1, 0, -1};
//     int m{rooms.size()};
//     if (m == 0)
//         return;
//     int n{rooms[0].size()};
//     queue<pair<int, int>> gates;
//     for (size_t i = 0; i < m; i++)
//     {
//         for (size_t j = 0; j < n; j++)
//         {
//             if (rooms[i][j] == 0)
//                 gates.push(make_pair(i, j));
//         }
//     }
//     while (!gates.empty())
//     {
//         queue<pair<int, int>> ap; // avaialable_place
//         ap.push(gates.front());
//         gates.pop();
//         while (!ap.empty())
//         {
//             pair<int, int> p = ap.front();
//             ap.pop();
//             for (int i = 0; i < 4; i++)
//             {
//                 int nx{p.first + mx[i]};
//                 int ny{p.second + my[i]};
//                 if (0 <= nx && nx < m && 0 <= ny && ny < n && rooms[nx][ny] > rooms[p.first][p.second] + 1)
//                 {
//                     rooms[nx][ny] = rooms[p.first][p.second] + 1;
//                     ap.push(make_pair(nx, ny));
//                 }
//             }
//         }
//     }
// }
