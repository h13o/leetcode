/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 *
 * https://leetcode.com/problems/k-th-symbol-in-grammar/description/
 *
 * algorithms
 * Medium (37.31%)
 * Likes:    292
 * Dislikes: 98
 * Total Accepted:    21.3K
 * Total Submissions: 57K
 * Testcase Example:  '1\n1'
 *
 * On the first row, we write a 0. Now in every subsequent row, we look at the
 * previous row and replace each occurrence of 0 with 01, and each occurrence
 * of 1 with 10.
 *
 * Given row N and index K, return the K-th indexed symbol in row N. (The
 * values of K are 1-indexed.) (1 indexed).
 *
 *
 * Examples:
 * Input: N = 1, K = 1
 * Output: 0
 *
 * Input: N = 2, K = 1
 * Output: 0
 *
 * Input: N = 2, K = 2
 * Output: 1
 *
 * Input: N = 4, K = 5
 * Output: 1
 *
 * Explanation:
 * row 1: 0
 * row 2: 01
 * row 3: 0110
 * row 4: 01101001
 *
 *
 * Note:
 *
 *
 * N will be an integer in the range [1, 30].
 * K will be an integer in the range [1, 2^(N-1)].
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int kthGrammar(int N, int K)
    {
        return rec(K);
    }
    int rec(int k)
    {
        if (k == 1)
            return 0;
        int v = rec((k + 1) / 2);
        return (!v && !(k % 2) || v && (k % 2)) ? 1 : 0;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int kthGrammar(int N, int K)
//     {
//         if (K == 1 && N == 1)
//             return 0;
//         int i = kthGrammar(N - 1, (K + 1) / 2);
//         if (i && !(K % 2) || !i && K % 2)
//             return 0;
//         return 1;
//     }
// };
