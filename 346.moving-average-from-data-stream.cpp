/*
 * @lc app=leetcode id=346 lang=cpp
 *
 * [346] Moving Average from Data Stream
 *
 * https://leetcode.com/problems/moving-average-from-data-stream/description/
 *
 * algorithms
 * Easy (68.27%)
 * Likes:    399
 * Dislikes: 46
 * Total Accepted:    96.9K
 * Total Submissions: 141.9K
 * Testcase Example:  '["MovingAverage","next","next","next","next"]\n[[3],[1],[10],[3],[5]]'
 *
 * Given a stream of integers and a window size, calculate the moving average
 * of all integers in the sliding window.
 *
 * Example:
 *
 *
 * MovingAverage m = new MovingAverage(3);
 * m.next(1) = 1
 * m.next(10) = (1 + 10) / 2
 * m.next(3) = (1 + 10 + 3) / 3
 * m.next(5) = (10 + 3 + 5) / 3
 *
 *
 *
 *
 */

// @lc code=start
class MovingAverage
{
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int max_size;
    MovingAverage(int size)
    {
        max_size = size;
    }

    double next(int val)
    {
        if (q.size() == max_size)
            q.pop();
        q.push(val);
        int count{};
        double sum{};
        queue<int> q2 = q;
        while (!q2.empty())
        {
            sum += q2.front();
            q2.pop();
            count++;
        }
        return sum / count;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
// @lc code=end
