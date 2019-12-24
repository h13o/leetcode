/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (30.21%)
 * Likes:    1448
 * Dislikes: 484
 * Total Accepted:    292.4K
 * Total Submissions: 964.9K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 *
 * Example:
 *
 *
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0;
        vector<bool> prime(n, true);
        int i = 2;
        int count{};
        while (i < n)
        {
            if (prime[i - 1])
            {
                int j = i * 2;
                while (j < n)
                {
                    if (prime[j - 1])
                    {
                        prime[j - 1] = false;
                        count++;
                    }
                    j += i;
                }
            }
            i++;
        }
        return n - 2 - count;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int countPrimes(int n)
//     {
//         vector<int> prime;
//         for (int i = 2; i < n; i++)
//         {
//             bool check{};
//             for (auto p : prime)
//             {
//                 if (i % p == 0)
//                 {
//                     check = true;
//                     break;
//                 }
//             }
//             if (!check)
//                 prime.push_back(i);
//         }
//         return prime.size();
//     }
// };
