/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 *
 * https://leetcode.com/problems/open-the-lock/description/
 *
 * algorithms
 * Medium (48.21%)
 * Likes:    544
 * Dislikes: 28
 * Total Accepted:    32.8K
 * Total Submissions: 68K
 * Testcase Example:  '["0201","0101","0102","1212","2002"]\n"0202"'
 *
 *
 * You have a lock in front of you with 4 circular wheels.  Each wheel has 10
 * slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'.  The wheels can
 * rotate freely and wrap around: for example we can turn '9' to be '0', or '0'
 * to be '9'.  Each move consists of turning one wheel one slot.
 *
 * The lock initially starts at '0000', a string representing the state of the
 * 4 wheels.
 *
 * You are given a list of deadends dead ends, meaning if the lock displays any
 * of these codes, the wheels of the lock will stop turning and you will be
 * unable to open it.
 *
 * Given a target representing the value of the wheels that will unlock the
 * lock, return the minimum total number of turns required to open the lock, or
 * -1 if it is impossible.
 *
 *
 * Example 1:
 *
 * Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
 * Output: 6
 * Explanation:
 * A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" ->
 * "1201" -> "1202" -> "0202".
 * Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202"
 * would be invalid,
 * because the wheels of the lock become stuck after the display becomes the
 * dead end "0102".
 *
 *
 *
 * Example 2:
 *
 * Input: deadends = ["8888"], target = "0009"
 * Output: 1
 * Explanation:
 * We can turn the last wheel in reverse to move from "0000" -> "0009".
 *
 *
 *
 * Example 3:
 *
 * Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"],
 * target = "8888"
 * Output: -1
 * Explanation:
 * We can't reach the target without getting stuck.
 *
 *
 *
 * Example 4:
 *
 * Input: deadends = ["0000"], target = "8888"
 * Output: -1
 *
 *
 *
 * Note:
 *
 * The length of deadends will be in the range [1, 500].
 * target will not be in the list deadends.
 * Every string in deadends and the string target will be a string of 4 digits
 * from the 10,000 possibilities '0000' to '9999'.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        vector<int> dist(10000, -1);
        for (auto d : deadends)
        {
            dist[stoi(d)] = INT_MIN;
            if (d == "0000")
                return -1;
        }
        vector<int> pn{1, -1};
        dist[0] = 0;
        queue<string> que;
        que.push("0000");
        while (!que.empty())
        {
            for (int i = 0; i < 4; i++)
            {
                for (auto j : pn)
                {
                    string temp = que.front();
                    temp[i] = (temp[i] - (int)'0' + j + 10) % 10 + '0';
                    if (dist[stoi(temp)] == -1)
                    {
                        dist[stoi(temp)] = dist[stoi(que.front())] + 1;
                        que.push(temp);
                    }
                }
            }
            que.pop();
        }
        return dist[stoi(target)];
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int openLock(vector<string> &deadends, string target)
//     {
//         vector<int> data(10000, -1);
//         data[0] = 0;
//         for (auto d : deadends)
//         {
//             if (d == "0000")
//                 return -1;
//             data[stoi(d)] = INT_MIN;
//         }
//         queue<string> que;
//         que.push("0000");
//         while (!que.empty())
//         {
//             string s = que.front();
//             que.pop();
//             for (int i = 0; i < 4; i++)
//             {
//                 for (int j : {1, -1})
//                 {
//                     int dgt = (int)s[i] - (int)'0';
//                     dgt = (dgt + j + 10) % 10;
//                     string t = s;
//                     t[i] = (char)(dgt + (int)'0');
//                     if (data[stoi(t)] == -1)
//                     {
//                         if (t == target)
//                             return data[stoi(s)] + 1;
//                         data[stoi(t)] = data[stoi(s)] + 1;
//                         que.push(t);
//                     }
//                 }
//             }
//         }
//         return data[stoi(target)];
//     }
// };
