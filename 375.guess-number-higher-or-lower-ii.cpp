/*
 * @lc app=leetcode id=375 lang=cpp
 *
 * [375] Guess Number Higher or Lower II
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/
 *
 * algorithms
 * Medium (39.06%)
 * Likes:    642
 * Dislikes: 919
 * Total Accepted:    52.3K
 * Total Submissions: 133.7K
 * Testcase Example:  '1'
 *
 * We are playing the Guess Game. The game is as follows:
 *
 * I pick a number from 1 to n. You have to guess which number I picked.
 *
 * Every time you guess wrong, I'll tell you whether the number I picked is
 * higher or lower.
 *
 * However, when you guess a particular number x, and you guess wrong, you pay
 * $x. You win the game when you guess the number I picked.
 *
 * Example:
 *
 *
 * n = 10, I pick 8.
 *
 * First round:  You guess 5, I tell you that it's higher. You pay $5.
 * Second round: You guess 7, I tell you that it's higher. You pay $7.
 * Third round:  You guess 9, I tell you that it's lower. You pay $9.
 *
 * Game over. 8 is the number I picked.
 *
 * You end up paying $5 + $7 + $9 = $21.
 *
 *
 * Given a particular n ≥ 1, find out how much money you need to have to
 * guarantee a win.
 */

// @lc code=start
class Solution
{
public:
    int getMoneyAmount(int n)
    {
        if (n <= 3) return n-1;
        vector<vector<int>> dp (n, vector<int>(n, -1));
        for (int i=0; i<n; i++)
            dp[i][i]=0;
        for (int i=0; i<n-1; i++)
            dp[i][i+1]=i+1;
        for (int i=0; i<n-2; i++)
            dp[i][i+2]=i+2;
        return rec(0, n-1, dp);
    }
    int rec(int r, int c, vector<vector<int>> &dp){
        if (dp[r][c] != -1) return dp[r][c];
        int min_val{INT_MAX};
        for (int i= r+1; i<c; i++){
            min_val = min(min_val, i+1 + max(rec(r,i-1, dp),rec(i+1,c,dp)));
        }
        dp[r][c] = min_val;
        return dp[r][c];
    }
};
// @lc code=end
